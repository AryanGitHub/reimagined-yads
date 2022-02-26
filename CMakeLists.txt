cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

# set the project name and version
project(yads VERSION 1.0)

add_subdirectory(libs/FileIO)

add_executable(${PROJECT_NAME} main.c init.c)


find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR})


target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES} libfileio)
