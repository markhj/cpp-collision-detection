#ifndef COLLISION_DETECTION_RECT_HPP
#define COLLISION_DETECTION_RECT_HPP

#include <glm/vec2.hpp>

#include "shape-2d.hpp"

class Rect_CS2D : public Shape_CS2D {
public:
    explicit Rect_CS2D(glm::vec2 size) : size(size) { }

    std::vector<Line_CS2D> getLinesWithoutTransforms() final;

private:
    glm::vec2 size;

};

#endif
