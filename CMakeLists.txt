cmake_minimum_required(VERSION 3.5)

project(exo3)

list(APPEND CMAKE_SYSTEM_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
find_package(Imagine REQUIRED)


add_executable(exo3 main.cpp)

include(GNUInstallDirs)

target_link_libraries(exo3 Imagine::Graphics)
