#ifndef FLOGGER_HPP
#define FLOGGER_HPP

#include <memory>
#include <spdlog/spdlog.h>

class FLogger
{
public:
    static void init();

    static std::shared_ptr<spdlog::logger>& getLogger()
    {
        return s_Logger;
    }
private:
    static std::shared_ptr<spdlog::logger> s_Logger;
};

#define LOG_TRACE(...)    ::FLogger::getLogger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)    ::FLogger::getLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...)     ::FLogger::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)     ::FLogger::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)    ::FLogger::getLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::FLogger::getLogger()->critical(__VA_ARGS__)

#endif