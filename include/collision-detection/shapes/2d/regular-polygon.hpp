#ifndef COLLISION_DETECTION_REGULAR_POLYGON_HPP
#define COLLISION_DETECTION_REGULAR_POLYGON_HPP

#include <stdexcept>
#include "shape-2d.hpp"

class RegularPolygon_CS2D : public Shape_CS2D {
public:
    explicit RegularPolygon_CS2D(unsigned int sides, double radius) : sides(sides), radius(radius)
    {
        if (sides < 3) {
            throw std::runtime_error("There must be at least 3 sides in a regular polygon");
        }
    }

    std::vector<Line_CS2D> getLinesWithoutTransforms() final;

private:
    unsigned int sides;

    double radius;

};

#endif
