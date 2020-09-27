project(learn_and_prep)
cmake_minimum_required(VERSION 3.15)
set (CMAKE_CXX_STANDARD 11)
find_package(Threads)

# Add More include paths here this won't impact system control
set(INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include 
             ${CMAKE_CURRENT_SOURCE_DIR}/basic_cpp
             ${CMAKE_CURRENT_SOURCE_DIR}/lists
             ${CMAKE_CURRENT_SOURCE_DIR}/simpletests}
)
include_directories(${INCLUDES})

# Add all targets here 

#basic c++ scratch plus
set(LOGGER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/basic_cpp/logger.cpp)
add_executable(logger ${LOGGER_SOURCES})
set(STRINGOPS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/basic_cpp/stringops.cpp)
add_executable(stringops ${STRINGOPS_SOURCES})
set(REFTEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/basic_cpp/reftest.cpp)
add_executable(reftest ${REFTEST_SOURCES})
set(RULESPOLY_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/basic_cpp/rulespolymorph.cpp)
add_executable(rulespolymorph ${RULESPOLY_SOURCES})
set(TEMPLATE_INHERITANCE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/basic_cpp/template_inheritance.cpp)
add_executable(template_inheritance ${TEMPLATE_INHERITANCE_SOURCES})
set(SYSLOGTEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/basic_cpp/syslogtest.cpp)
add_executable(syslogtest ${SYSLOGTEST_SOURCES})
target_link_libraries(syslogtest Threads::Threads)


#simple tests - for datastructures 
set(NODETEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/simpletests/NodeTest.cpp)
add_executable(NodeTest ${NODETEST_SOURCES})
set(LISTNODETEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/simpletests/ListNodeTest.cpp)
add_executable(ListNodeTest ${LISTNODETEST_SOURCES})
set(SINGLELISTTEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/simpletests/SingleListTest.cpp)
add_executable(SingleListTest ${SINGLELISTTEST_SOURCES})
set(DOUBLELISTTEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/simpletests/DoubleListTest.cpp)
add_executable(DoubleListTest ${DOUBLELISTTEST_SOURCES})




