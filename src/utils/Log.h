#ifndef LOG_H
#define LOG_H

#include <any>
#include <mutex>
#include <queue>
#include <thread>
#include <iostream>
#include <sstream>
#include <condition_variable>
#include <memory>
#include "config.h"

namespace HttpReactor
{
    enum class LogLevel
    {
        DEBUG = 0,
        INFO = 1,
        WARN = 2,
        ERROR = 3
    };
    class LogTask // 日志任务
    {
    public:
        LogTask() {} // 默认构造函数
        LogTask(LogTask &src) : level(src.level), msg(src.msg) {}
        LogTask(LogTask &&src) : level(src.level), msg(std::move(src.msg)) {}
        ~LogTask() {};
        LogLevel level;
        std::queue<std::any> msg;
    };
    class AsyncLog
    {
    public:
        static AsyncLog &getInstance() // 基于静态变量实现单例模式
        {
            static AsyncLog instance;
            return instance;
        }

        ~AsyncLog()
        {
            Stop();
            workthread.join();
            std::cout << "exit success" << std::endl;
        }

        template <typename T> // 将数据转换为any类型
        std::any toAny(T &value)
        {
            return std::any(value);
        }

        template <typename Arg, typename... Args>
        void TaskEnque(std::shared_ptr<LogTask> task, Arg &&arg, Args &&...args)
        {
            task->msg.push(toAny(arg));
            TaskEnque(task, std::forward<Args>(args)...); // 递归调用
        }

        template <typename Arg>
        void TaskEnque(std::shared_ptr<LogTask> task, Arg &&arg)
        {
            task->msg.push(toAny(arg));
        }

        template <typename... Args>
        void AsyncWrite(LogLevel level, Args &&...args)
        {
            auto task = std::make_shared<LogTask>();
            task->level = level;
            TaskEnque(task, std::forward<Args>(args)...);
            std::unique_lock<std::mutex> lock(_mutex);
            _taskQueue.push(task);
            bool notity = !_taskQueue.empty();
            lock.unlock();
            if (notity)
            {
                _em.notify_one();
            }
        }
        void Stop()
        {
            _stop = true;
            _em.notify_one();
        }

    private:
        AsyncLog() : _stop(false)
        {
            init();
        }

        bool convertToString(std::any value, std::string &str)
        {
            std::ostringstream ss;
            if (value.type() == typeid(int))
            {
                ss << std::any_cast<int>(value);
            }
            else if (value.type() == typeid(double))
            {
                ss << std::any_cast<double>(value);
            }
            else if (value.type() == typeid(std::string))
            {
                ss << std::any_cast<std::string>(value);
            }
            else if (value.type() == typeid(char *))
            {
                ss << std::any_cast<char *>(value);
            }
            else if (value.type() == typeid(char const *))
            {
                ss << std::any_cast<char const *>(value);
            }
            else
            {
                return false;
            }
            str = ss.str();
            return true;
        }

        void processTask(std::shared_ptr<LogTask> task)
        {
            auto t = time(nullptr);
            auto tm = localtime(&t);
            std::string today = std::to_string(1900 + tm->tm_year) + "-" + std::to_string(1 + tm->tm_mon) + "-" + std::to_string(tm->tm_mday);
            if (today != m_today)
            {
                m_today = today;
                std::string _dir = dir;
                std::string filename = _dir + "/" + today + ".log";
                m_fp = fopen(filename.c_str(), "a");
            }
            if (!m_fp)
            {
                perror("open file failed");
                return;
            }
            std::string log = ""; // 要打印的日志
            std::string time = std::to_string(tm->tm_hour) + ":" + std::to_string(tm->tm_min) + ":" + std::to_string(tm->tm_sec) + "      ";
            log += time;
            log += "["+getLogLevelString(task->level) +"]"+"      ";
            if (task->msg.empty())
            {
                perror("msg is empty");
                return;
            }
            auto data = task->msg.front();
            task->msg.pop();
            std::string formatstr = "";
            bool bsuccess = convertToString(data, formatstr);
            if (!bsuccess)
            {
                return;
            }

            for (; !(task->msg.empty());)
            {
                auto data = task->msg.front();
                formatstr = formatString(formatstr, data);
                task->msg.pop();
            }
            log += formatstr;
            int res = fprintf(m_fp, "%s\n", log.c_str());
            if (res < 0)
            {
                perror("write file failed");
                return;
            }
            fflush(m_fp); // 立即刷新缓冲区，将日志写入文件
        }
        template <typename... Args>
        std::string formatString(const std::string &format, Args... args)
        {
            std::string result = format;
            size_t pos = 0;
            // lambda表达式查找并替换字符串
            auto replacePlaceholder = [&](const std::string &placeholder, const std::any &replacement)
            {
                std::string str_replement = "";
                bool bsuccess = convertToString(replacement, str_replement);
                if (!bsuccess)
                {
                    perror("convertToString failed");
                    return;
                }

                size_t placeholderPos = result.find(placeholder, pos);
                if (placeholderPos != std::string::npos)
                {
                    result.replace(placeholderPos, placeholder.length(), str_replement);
                    pos = placeholderPos + str_replement.length();
                }
                else
                {
                    result = result + " " + str_replement;
                }
            };

            (replacePlaceholder("{}", args), ...);
            return result;
        }
        void init()
        {
            dir = Config::getInstance().getLogConfig().dir;
            auto t = time(nullptr);
            auto tm = localtime(&t);
            m_today = std::to_string(1900 + tm->tm_year) + "-" + std::to_string(1 + tm->tm_mon) + "-" + std::to_string(tm->tm_mday);
            filename = dir + std::to_string(1900 + tm->tm_year) + "-" + std::to_string(1 + tm->tm_mon) + "-" + std::to_string(tm->tm_mday) + ".log";
            m_fp = fopen(filename.c_str(), "a");
            workthread = std::thread([this]()
                                     {
                    while(true)
                    {
                        std::unique_lock<std::mutex> lock(_mutex);
                        while(_taskQueue.empty()&&!_stop)
                        {
                            _em.wait(lock);
                        }
                        if(_stop) return;
                        auto task=_taskQueue.front();
                        _taskQueue.pop();
                        processTask(task);
                        lock.unlock();
                    } });
        }
        std::string getLogLevelString(LogLevel level)
        {
            switch (level)
            {
            case LogLevel::DEBUG:
                return "DEBUG";
            case LogLevel::INFO:
                return "INFO";
            case LogLevel::WARN:
                return "WARN";
            case LogLevel::ERROR:
                return "ERROR";
            default:
                return "UNKNOWN";
            }
        }
        const char *dir;      // 日志文件目录
        std::string filename; // 日志文件名
        std::string m_today;  // 记录当前日期(日志文件按照日期分割)
        FILE *m_fp;           // 日志文件指针
        std::mutex _mutex;
        std::condition_variable _em;
        std::thread workthread;
        bool _stop; // 是否停止
        std::queue<std::shared_ptr<LogTask>> _taskQueue;
    };
    template <typename... Args>
    void ELog(Args &&...args)
    {
        AsyncLog::getInstance().AsyncWrite(LogLevel::ERROR, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void DLog(Args &&...args)
    {
        AsyncLog::getInstance().AsyncWrite(LogLevel::DEBUG, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void ILog(Args &&...args)
    {
        AsyncLog::getInstance().AsyncWrite(LogLevel::INFO, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void WLog(Args &&...args)
    {
        AsyncLog::getInstance().AsyncWrite(LogLevel::WARN, std::forward<Args>(args)...);
    }

};
#endif