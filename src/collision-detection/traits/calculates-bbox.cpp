#include "collision-detection/traits/calculates-bbox.hpp"

glm::vec2 CalculatesBoundingBoxes::calculateBounds(const std::vector<Line_CS2D>& lines)
{
    glm::vec2 min(0.0), max(0.0);

    for (Line_CS2D line : lines) {
        if (line.a.x < min.x) {
            min.x = line.a.x;
        }

        if (line.b.x < min.x) {
            min.x = line.b.x;
        }

        if (line.a.x > max.x) {
            max.x = line.a.x;
        }

        if (line.b.x > max.x) {
            max.x = line.b.x;
        }

        if (line.a.y < min.y) {
            min.y = line.a.y;
        }

        if (line.b.y < min.y) {
            min.y = line.b.y;
        }

        if (line.a.y > max.y) {
            max.y = line.a.y;
        }

        if (line.b.y > max.y) {
            max.y = line.b.y;
        }
    }

    return {max.x - min.x, max.y - min.y};
}
