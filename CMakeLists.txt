cmake_minimum_required(VERSION 3.15)
project(flogger CXX)

add_library(flogger STATIC 
    src/flogger.cpp
    include/flogger/flogger.hpp
)

target_link_libraries(flogger PRIVATE spdlog::spdlog)

target_include_directories(flogger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

install(DIRECTORY include/DESTINATION .)

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