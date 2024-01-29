#include "collision-detection/shapes/2d/rect.hpp"

std::vector<Line_CS2D> Rect_CS2D::getLinesWithoutTransforms()
{
    double x = size.x / 2.0;
    double y = size.y / 2.0;

    return {
        // Left
        Line_CS2D({.a = {-x, -y}, .b = {-x, y}}),

        // Top
        Line_CS2D({ .a = {-x, y}, .b = {x, y}}),

        // Right
        Line_CS2D({ .a = {x, y}, .b = {x, -y}}),

        // Bottom
        Line_CS2D({ .a = {x, -y}, .b = {-x, -y}}),
    };
}
