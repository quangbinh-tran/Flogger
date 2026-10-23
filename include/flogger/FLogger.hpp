#ifndef FLOGGER_HPP
#define FLOGGER_HPP

#include <memory>

#include <spdlog/logger.h>
#include <spdlog/spdlog.h>

class FLogger
{
public:
    static std::shared_ptr<spdlog::logger>& Get();

    static void SetLevel(spdlog::level::level_enum level);

private:
    FLogger() = delete;
    ~FLogger() = delete;
    FLogger(const FLogger&) = delete;
    FLogger& operator=(const FLogger&) = delete;
};

#define LOG_TRACE(...)    ::FLogger::Get()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)    ::FLogger::Get()->debug(__VA_ARGS__)
#define LOG_INFO(...)     ::FLogger::Get()->info(__VA_ARGS__)
#define LOG_WARN(...)     ::FLogger::Get()->warn(__VA_ARGS__)
#define LOG_ERROR(...)    ::FLogger::Get()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::FLogger::Get()->critical(__VA_ARGS__)

#endif