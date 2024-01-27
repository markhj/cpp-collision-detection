#ifndef COLLISION_DETECTION_CALCULATES_BBOX_HPP
#define COLLISION_DETECTION_CALCULATES_BBOX_HPP

#include <vector>
#include "collision-detection/bounding-volumes/aabb-2d.hpp"
#include "collision-detection/shapes/primitives/lines.hpp"

class CalculatesBoundingBoxes {
protected:
    [[nodiscard]] static glm::vec2 calculateBounds(const std::vector<Line_CS2D>& lines) ;

};

#endif
