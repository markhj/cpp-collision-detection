#include "collision-detection/bounding-volumes/aabb-2d.hpp"

std::vector<Line_CS2D> AABB_CS2D::splitIntoLines()
{
    float ax = global_a.x;
    float ay = global_a.y;
    float bx = global_b.x;
    float by = global_b.y;

    return {
        {{ax, ay}, {ax, by}},
        {{ax, by}, {bx, by}},
        {{bx, by}, {bx, ay}},
        {{bx, ay}, {ax, ay}}
    };
}
