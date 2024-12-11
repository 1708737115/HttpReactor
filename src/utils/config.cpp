#include "config.h"

namespace HttpReactor
{
    Config& Config::getInstance()
    {
        static Config instance;
        return instance;
    }
    void Config::LoadConfig(std::string filename)
    {

        HttpReactor::IniFile ini(filename.c_str());
        m_log.dir = ini.get("Log", "dir");
    }
};
