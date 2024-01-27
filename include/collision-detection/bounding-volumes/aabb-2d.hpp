#ifndef COLLISION_DETECTION_AABB_2D_HPP
#define COLLISION_DETECTION_AABB_2D_HPP

#include "collision-detection/contracts/aabb.hpp"
#include "collision-detection/shapes/primitives/lines.hpp"

#include <glm/vec2.hpp>

class AABB_CS2D : public AABB<glm::vec2, Line_CS2D> {
public:
    glm::vec2 size, global_a, global_b;

    std::vector<Line_CS2D> splitIntoLines() override;

};

#endif
