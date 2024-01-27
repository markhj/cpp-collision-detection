#ifndef COLLISION_DETECTION_COLLISIONS_HPP
#define COLLISION_DETECTION_COLLISIONS_HPP

#include <vector>
#include "intersections.hpp"
#include "collision-detection/shapes/2d/shape-2d.hpp"

template <typename Intersection_CSXD, typename Shape_CSXD>
class Collision {
public:
    std::vector<Intersection_CSXD> intersections;

    std::vector<Shape_CSXD*> shapes;

};

class Collision_CS2D : public Collision<Intersection_CS2D, Shape_CS2D> {

};

#endif
