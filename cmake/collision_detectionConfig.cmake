include(CMakePackageConfigHelpers)

# Store the absolute path to the root of the library in COLLISION_DETECTION_LIB_DIR
get_filename_component(COLLISION_DETECTION_LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

# Load the file lists which will be parsed into COLLISION_DETECTION_HEADER_FILES
# and COLLISION_DETECTION_SOURCE_FILES respectively
include(${COLLISION_DETECTION_LIB_DIR}/cmake/file_list.cmake)

add_library(collision_detection
        ${COLLISION_DETECTION_HEADER_FILES}
        ${COLLISION_DETECTION_SOURCE_FILES}
)

# Ensure the "include" directory is accessible to the client project
target_include_directories(collision_detection
        PUBLIC
        $<BUILD_INTERFACE:${COLLISION_DETECTION_LIB_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Export the targets file
export(TARGETS collision_detection
        FILE ${CMAKE_CURRENT_BINARY_DIR}/collision-detectionTargets.cmake)

# Install CMake files
install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/collision-detectionConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/collision-detectionConfigVersion.cmake"
        DESTINATION lib/cmake/collision-detection
)

find_package(glm REQUIRED)

target_link_libraries(collision_detection PRIVATE glm)
