#include <cmath>
#include "collision-detection/shapes/2d/regular-polygon.hpp"

std::vector<Line_CS2D> RegularPolygon_CS2D::getLinesWithoutTransforms()
{
    std::vector<Line_CS2D> list;

    double currentAngle = 0.0;

    for (unsigned int i = 1; i <= sides; i++) {
        double nextAngle = i * 2 * M_PI / sides;
        list.push_back({
            .a = { radius * sin(currentAngle), radius * cos(currentAngle) },
            .b = { radius * sin(nextAngle), radius * cos(nextAngle) },
        });
        currentAngle = nextAngle;
    }

    return list;
}
