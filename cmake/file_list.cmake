set(COLLISION_DETECTION_HPP
        # Public header
        public.hpp

        # Contracts
        contracts/aabb.hpp
        contracts/collision-shape.hpp
        contracts/collision-detector.hpp

        # Traits
        traits/id-generator.hpp
        traits/processes-layers-masks.hpp
        traits/calculates-bbox.hpp

        # Bounding volumes
        bounding-volumes/aabb-2d.hpp

        # Shapes
        shapes/primitives/lines.hpp
        shapes/2d/shape-2d.hpp
        shapes/2d/rect.hpp
        shapes/2d/regular-polygon.hpp

        # Detection
        detection/collisions.hpp
        detection/line-intersection.hpp
        detection/collision-detector-2d.hpp

        # Partitioning
        partitioning/partitions.hpp
        partitioning/partitions-2d.hpp
        )

set(COLLISION_DETECTION_CPP
        # Traits
        traits/id-generator.cpp
        traits/processes-layers-masks.cpp
        traits/calculates-bbox.cpp

        # Bounding volumes
        bounding-volumes/aabb-2d.cpp

        # Shapes
        shapes/2d/shape-2d.cpp
        shapes/2d/rect.cpp
        shapes/2d/regular-polygon.cpp

        # Collision detectors
        detection/collision-detector-2d.cpp
        detection/line-intersection.cpp

        # Partitioning
        partitioning/partitions-2d.cpp
        )

set(COLLISION_DETECTION_HEADER_FILES "")
set(COLLISION_DETECTION_SOURCE_FILES "")

foreach (HPP_FILE ${COLLISION_DETECTION_HPP})
    list(APPEND COLLISION_DETECTION_HEADER_FILES "${COLLISION_DETECTION_LIB_DIR}/include/collision-detection/${HPP_FILE}")
endforeach ()

foreach (CPP_FILE ${COLLISION_DETECTION_CPP})
    list(APPEND COLLISION_DETECTION_SOURCE_FILES "${COLLISION_DETECTION_LIB_DIR}/src/collision-detection/${CPP_FILE}")
endforeach ()
