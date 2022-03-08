cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

# set the project name and version
project(yads VERSION 1.0)

add_subdirectory(libs/FileIO)
add_subdirectory(libs/ListFileIO)
add_subdirectory(libs/DownloadFile)

find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR} libs ${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.c directoryVariables.c init.c categoryHandling/createCategory.c categoryHandling/categoryStructHandling.c categoryHandling/userAddedListOfURLsHandling.c categoryHandling/categoryFilesPath.c categoryHandling/listOfListsHandling.c categoryHandling/downloadLists.c)

target_link_libraries(${PROJECT_NAME} libFileIO libListFileIO libDownloadFile ${CURL_LIBRARIES})
