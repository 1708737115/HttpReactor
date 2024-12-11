#include "../src/utils/Log.h"

using namespace HttpReactor;

void testThread(int id)
{
    for (int i = 0; i < 10; ++i)
    {
        std::stringstream ss;
        ss << "Thread " << id << " log entry " << i;
        ILog(ss.str());
    }
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i)
    {
        threads.emplace_back(testThread, i);
    }

    for (auto &t : threads)
    {
        t.join();
    }

    // 模拟程序结束
    AsyncLog::getInstance().Stop();
    return 0;
}