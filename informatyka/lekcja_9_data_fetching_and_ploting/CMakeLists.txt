cmake_minimum_required(VERSION 3.30)
project(lekcja_9_data_fetching_and_ploting)

set(CMAKE_CXX_STANDARD 20)


# Set the build output location to a common directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

add_subdirectory(OpenXLSX)

add_executable(lekcja_9_data_fetching_and_ploting main.cpp)
target_link_libraries(lekcja_9_data_fetching_and_ploting OpenXLSX::OpenXLSX)