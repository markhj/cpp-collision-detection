#ifndef COLLISION_DETECTION_LINE_INTERSECTION_HPP
#define COLLISION_DETECTION_LINE_INTERSECTION_HPP

#include <optional>
#include "collision-detection/shapes/primitives/lines.hpp"
#include "intersections.hpp"

class LineIntersectionDetector {
public:
    std::optional<Intersection_CS2D> intersects(Line_CS2D a, Line_CS2D b);

    std::optional<Intersection_CS3D> intersects(Line_CS3D a, Line_CS3D b);

};

#endif
