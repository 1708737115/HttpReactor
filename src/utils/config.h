#include <iostream>
#include "ini.h"

namespace HttpReactor{

typedef struct Log
{
    const char* dir;
}Log;

class Config{
    public:
        static Config& getInstance(); // 获取单例
        const Log& getLogConfig() const { return m_log; }
    private:
        Config():m_filename("/home/fengxu/mylib/HttpReactor/config/config.ini")
        {
            LoadConfig(m_filename);
        }
        void LoadConfig(std::string filename);
        std::string m_filename;
        Log m_log; // 日志配置
    };
}