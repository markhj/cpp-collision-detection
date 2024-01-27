#include <iostream>
#include <cmath>
#include "collision-detection/shapes/2d/shape-2d.hpp"
#include "collision-detection/traits/id-generator.hpp"

void Shape_CS2D::translate(glm::vec2 value)
{
    translation = value;
}

void Shape_CS2D::rotate(double value)
{
    rotation = value;
}

AABB_CS2D Shape_CS2D::getAABBWithoutTransforms()
{
    AABB_CS2D result = AABB_CS2D();
    result.size = calculateBounds(getLinesWithoutTransforms());
    glm::vec2 hs(result.size.x / 2.0, result.size.y / 2.0);
    result.global_a = glm::vec2(-hs.x, -hs.y);
    result.global_b = glm::vec2(hs.x, hs.y);
    return result;
}

AABB_CS2D Shape_CS2D::getAABBWithTransforms()
{
    AABB_CS2D aabb = getAABBWithoutTransforms();
    glm::vec2 hs(aabb.size.x / 2.0, aabb.size.y / 2.0);
    aabb.global_a = glm::vec2(-hs.x + translation.x, -hs.y + translation.y);
    aabb.global_b = glm::vec2(hs.x + translation.x, hs.y + translation.y);

    return aabb;
}

std::vector<Line_CS2D> Shape_CS2D::getLinesWithTransforms()
{
    std::vector<Line_CS2D> lines = getLinesWithoutTransforms();
    for (int i = 0; i <= lines.size() - 1; i++) {
        float ax = lines[i].a.x;
        float ay = lines[i].a.y;
        float bx = lines[i].b.x;
        float by = lines[i].b.y;

        lines[i].a.x = ax * cos(rotation) - ay * sin(rotation);
        lines[i].a.y = ax * sin(rotation) + ay * cos(rotation);
        lines[i].b.x = bx * cos(rotation) - by * sin(rotation);
        lines[i].b.y = bx * sin(rotation) + by * cos(rotation);

        lines[i].a += translation;
        lines[i].b += translation;
    }
    return lines;
}

unsigned int Shape_CS2D::getId()
{
    if (!id.has_value()) {
        id = IdGenerator::generateId();
    }
    return id.value();
}
