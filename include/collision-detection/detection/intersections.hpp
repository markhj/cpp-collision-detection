#ifndef COLLISION_DETECTION_INTERSECTIONS_HPP
#define COLLISION_DETECTION_INTERSECTIONS_HPP

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

template <typename glmVecX>
class Intersection {
public:
    glmVecX point;

};

class Intersection_CS2D : public Intersection<glm::vec2> {
public:
    glm::vec2 point;

};

class Intersection_CS3D : public Intersection<glm::vec3> {
public:
    glm::vec3 point;

};

#endif
