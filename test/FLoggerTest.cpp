#include <gtest/gtest.h>

#include <flogger/FLogger.hpp>

TEST(FLoggerTest, GetReturnsSameLoggerInstance)
{
    auto& logger1 = FLogger::Get();
    auto& logger2 = FLogger::Get();

    EXPECT_EQ(logger1.get(), logger2.get());
}

TEST(FLoggerTest, SetLevelUpdatesLoggerLevel)
{
    const auto originalLevel = FLogger::Get()->level();

    FLogger::SetLevel(spdlog::level::warn);
    EXPECT_EQ(FLogger::Get()->level(), spdlog::level::warn);

    FLogger::SetLevel(originalLevel);
}

TEST(FLoggerTest, LoggerNameMatchesExpected)
{
    EXPECT_EQ(FLogger::Get()->name(), "FLOGGER");
}
