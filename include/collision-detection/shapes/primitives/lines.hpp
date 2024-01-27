#ifndef COLLISION_DETECTION_LINES_HPP
#define COLLISION_DETECTION_LINES_HPP

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

struct Line_CS2D {
    glm::vec2 a, b;
};

struct Line_CS3D {
    glm::vec3 a, b;
};

#endif
