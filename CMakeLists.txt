project(testin)

cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

set (TESTIN_ENABLED 0 CACHE STRING "Enable Testin build")

if ("${TESTIN_ENABLED}" EQUAL "1")
  add_definitions(-DTESTIN_ENABLED=1)
endif()

add_library(testin SHARED testin.cpp testin.h)
target_link_libraries(testin pthread)

add_library(my_library STATIC example.cpp example.h test2.cpp)

add_executable(example main.cpp)

target_link_libraries(example testin my_library)
