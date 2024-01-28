cmake_minimum_required(VERSION 3.2)
project(collision_detection)

set(CMAKE_CXX_STANDARD 20)
set(COLLISION_DETECTION_LIB_DIR "${CMAKE_CURRENT_LIST_DIR}")

find_package(glm REQUIRED)
find_package(cpp_bbunit REQUIRED)

include_directories(include)

# Load the file lists which will be parsed into COLLISION_DETECTION_HEADER_FILES
# and COLLISION_DETECTION_SOURCE_FILES respectively
include(cmake/file_list.cmake)

add_executable(test
        tests/main.cpp
        tests/2d/aabb2d-test.cpp
        tests/2d/aabb-2d-overlapping-test.cpp
        tests/2d/shape-2d-test.cpp
        tests/misc/line-intersection-test.cpp
        ${COLLISION_DETECTION_HEADER_FILES}
        ${COLLISION_DETECTION_SOURCE_FILES}
)

target_link_libraries(test PRIVATE glm cpp_bbunit)
