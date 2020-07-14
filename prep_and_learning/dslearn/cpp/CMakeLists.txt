project(learn_and_prep)
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD c++11)
set(CMAKE_CXX_FLAGS -ggdb)
# Add More include paths here this won't impact system control
set(INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include 
             ${CMAKE_CURRENT_SOURCE_DIR}/basic_cpp
)
include_directories(${INCLUDES})

# Add all targets here 
set(LOGGER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/basic_cpp/logger.cpp)
add_executable(logger ${LOGGER_SOURCES})
set(STRINGOPS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/basic_cpp/stringops.cpp)
add_executable(stringops ${STRINGOPS_SOURCES})


