#ifndef COLLISION_DETECTION_SHAPE_2D_HPP
#define COLLISION_DETECTION_SHAPE_2D_HPP

#include <glm/vec2.hpp>
#include "collision-detection/bounding-volumes/aabb-2d.hpp"
#include "collision-detection/contracts/collision-shape.hpp"
#include "collision-detection/shapes/primitives/lines.hpp"
#include "collision-detection/traits/calculates-bbox.hpp"

class Shape_CS2D : public CollisionShape<glm::vec2, double, AABB_CS2D, Line_CS2D>,
        public CalculatesBoundingBoxes {
public:
    void translate(glm::vec2 value) final;

    void rotate(double value) final;

    AABB_CS2D getAABBWithoutTransforms() final;

    AABB_CS2D getAABBWithTransforms() final;

    std::vector<Line_CS2D> getLinesWithTransforms() final;

    unsigned int getId() final;

protected:
    glm::vec2 translation = glm::vec2(0.0, 0.0);

    double rotation = 0.0;

};

#endif
