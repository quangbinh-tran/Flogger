#include "FLogger.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

std::shared_ptr<spdlog::logger> FLogger::s_Logger;

void FLogger::init()
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
        "log/app.log",
        1025 * 1024 * 5,
        3
    );

    console_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v");
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%l] [%s:%#] %v");
    std::vector<spdlog::sink_ptr> sinks
    {
        console_sink,
        file_sink
    };

    s_Logger = std::make_shared<spdlog::logger>(
        "APP",
        sinks.begin(),
        sinks.end()
    );

    s_Logger->set_level(spdlog::level::trace);
    s_Logger->flush_on(spdlog::level::err);
    spdlog::register_logger(s_Logger);
}
