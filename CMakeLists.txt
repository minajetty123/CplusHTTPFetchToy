cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(fetch_lukitu)
add_executable(${PROJECT_NAME} "main.cpp")
add_subdirectory(xmllukitu)
target_link_libraries(${PROJECT_NAME} xmllukitu)

