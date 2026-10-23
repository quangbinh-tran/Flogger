#include <flogger/FLogger.hpp>

#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger>& FLogger::Get()
{
    static std::shared_ptr<spdlog::logger> logger = []()
    {
        auto l = spdlog::stdout_color_mt("FLOGGER");

        l->set_pattern(
            "[%Y-%m-%d %H:%M:%S] [%^%-l%$] %v"
        );

        l->set_level(spdlog::level::trace);

        return l;
    }();

    return logger;
}

void FLogger::SetLevel(spdlog::level::level_enum level)
{
    Get()->set_level(level);
}