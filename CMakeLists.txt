cmake_minimum_required(VERSION 3.28)
project(shtm)

include_directories(include/)
add_executable(shtm src/main.cpp src/rc.cpp src/shtm.cpp src/task.cpp)