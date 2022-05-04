cmake_minimum_required(VERSION 3.4.1)

project(fetch_lukitu)
find_package(CURL REQUIRED)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(${PROJECT_NAME} "main.cpp" "util/worker_thread.h" "util/semaphore.h")
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES})

