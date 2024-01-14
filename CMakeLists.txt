cmake_minimum_required(VERSION 3.28)
project(shtmapi)

include_directories(include/)
add_library(shtmapi SHARED src/rc.cpp src/shtm.cpp src/task.cpp src/error.cpp src/custom.cpp)
set_target_properties(shtmapi PROPERTIES PUBLIC_HEADER include/shtm.hpp)
target_include_directories(shtmapi PRIVATE .)
set_property(TARGET shtmapi PROPERTY CXX_STANDARD 23)
include(GNUInstallDirs)
install(TARGETS shtmapi
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

project(shtm)
add_executable(shtm src/main.cpp)
set_property(TARGET shtm PROPERTY CXX_STANDARD 23)
target_link_libraries(shtm shtmapi)