cmake_minimum_required(VERSION 3.9.0)

set (CMAKE_VERBOSE_MAKEFILE ON)

set (NODE_MODULES_DIR "../node_modules")
set (COMMON_LIBRARY "../cpp")
set (INTERNAL_LIBRARY "./src/main/cpp")

include_directories(
            ${COMMON_LIBRARY}
            ${INTERNAL_LIBRARY}
            ${NODE_MODULES_DIR}/react-native/React
            ${NODE_MODULES_DIR}/react-native/React/Base
            ${NODE_MODULES_DIR}/react-native/ReactCommon/jsi
)

add_library(algorithms
            SHARED
            ${NODE_MODULES_DIR}/react-native/ReactCommon/jsi/jsi/jsi.cpp
            ${COMMON_LIBRARY}/algorithms_core.h
            ${COMMON_LIBRARY}/algorithms_core.cpp
            ${INTERNAL_LIBRARY}/AlgorithmsExtension.h
            ${INTERNAL_LIBRARY}/AlgorithmsExtension.cpp
            cpp-adapter.cpp
)

set_target_properties(
        algorithms PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        POSITION_INDEPENDENT_CODE ON
)

find_library(
        log-lib
        log
)

target_link_libraries(
        algorithms
        ${log-lib}
)
