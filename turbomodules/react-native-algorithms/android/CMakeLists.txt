cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)

include_directories(
            ../cpp
            ../../../node_modules/react-native/React
            ../../../node_modules/react-native/React/Base
            ../../../node_modules/react-native/ReactCommon/jsi
)

add_library(algorithms
            SHARED
            ../../../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
            ../cpp/algorithms_module.hpp
            ../cpp/algorithms_module.cpp
            ../cpp/dijkstra/dijkstra_algorithm.h
            ../cpp/dijkstra/dijkstra_algorithm.cpp
            cpp-adapter.cpp
)

target_link_libraries(algorithms)
