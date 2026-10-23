cmake_minimum_required(VERSION 3.15)
project(flogger CXX)

include(GNUInstallDirs)

find_package(spdlog CONFIG REQUIRED)
find_package(GTest REQUIRED)

enable_testing()

add_library(flogger STATIC
    src/FLogger.cpp
    include/flogger/FLogger.hpp
)

target_link_libraries(flogger PUBLIC spdlog::spdlog)

target_include_directories(flogger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_executable(flogger_tests
    test/FLoggerTest.cpp
)

target_link_libraries(flogger_tests PRIVATE
    flogger
    GTest::gtest_main
)

target_include_directories(flogger_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_test(NAME flogger_tests COMMAND flogger_tests)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS flogger
    EXPORT flogger-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(EXPORT flogger-targets
    FILE floggerConfig.cmake
    NAMESPACE flogger::
    DESTINATION share/flogger
)