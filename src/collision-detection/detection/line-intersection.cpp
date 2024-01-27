#include "collision-detection/detection/line-intersection.hpp"

#include <glm/gtc/constants.hpp>

std::optional<Intersection_CS2D> LineIntersectionDetector::intersects(Line_CS2D lineA, Line_CS2D lineB)
{
    glm::vec2 aDir = lineA.b - lineA.a;
    glm::vec2 bDir = lineB.b - lineB.a;

    float denominator = aDir.x * bDir.y - aDir.y * bDir.x;

    if (abs(denominator) < glm::epsilon<float>()) {
        return std::nullopt;
    }

    glm::vec2 c = lineB.a - lineA.a;

    float t = (c.x * bDir.y - c.y * bDir.x) / denominator;
    float u = (c.x * aDir.y - c.y * aDir.x) / denominator;

    if (t >= 0.0f && t <= 1.0f && u >= 0.0f && u <= 1.0f) {
        Intersection_CS2D intersection { };
        intersection.point = lineA.a + t * aDir;
        return intersection;
    }

    return std::nullopt;
}

/**
 * @todo To be implemented
 */
std::optional<Intersection_CS3D> LineIntersectionDetector::intersects(Line_CS3D a, Line_CS3D b)
{
    return std::nullopt;
}
