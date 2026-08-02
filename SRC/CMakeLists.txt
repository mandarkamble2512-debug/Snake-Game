cmake_minimum_required(VERSION 3.10)
project(Swift-Snake)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(Swift-Snake main.cpp)
target_link_libraries(Swift-Snake sfml-graphics sfml-window sfml-system)
