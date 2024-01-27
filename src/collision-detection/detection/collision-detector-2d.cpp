#include <iostream>
#include "collision-detection/detection/collision-detector-2d.hpp"

bool CollisionDetector_CS2D::hasLayerAndMaskIntersection(std::vector<int> aLayers,
                                                         std::vector<int> aMasks,
                                                         std::vector<int> bLayers,
                                                         std::vector<int> bMasks)
{
    return hasLayerAndMaskOverlap(aMasks, bLayers)
           || hasLayerAndMaskOverlap(bMasks, aLayers);
}

bool CollisionDetector_CS2D::aabbContainsPoint(AABB_CS2D aabb, glm::vec2 point)
{
    glm::vec2 a = aabb.global_a;
    glm::vec2 b = aabb.global_b;

    glm::vec2 min(a.x > b.x ? b.x : a.x, a.y > b.y ? b.y : a.y);
    glm::vec2 max(a.x < b.x ? b.x : a.x, a.y < b.y ? b.y : a.y);

    return point.x >= min.x && point.x <= max.x && point.y >= min.y && point.y <= max.y;
}

bool CollisionDetector_CS2D::aabbContainsAnyOf(AABB_CS2D aabb, std::vector<glm::vec2> points)
{
    for (glm::vec2 point : points) {
        if (aabbContainsPoint(aabb, point)) {
            return true;
        }
    }
    return false;
}

bool CollisionDetector_CS2D::aabbsOverlap(AABB_CS2D a, AABB_CS2D b)
{
    return aabbContainsAnyOf(a, {
        { b.global_a.x, b.global_a.y },
        { b.global_a.x, b.global_b.y },
        { b.global_b.x, b.global_a.y },
        { b.global_b.x, b.global_b.y },
    });
}

std::vector<Intersection_CS2D>
CollisionDetector_CS2D::getPolygonIntersections(std::vector<Line_CS2D> linesOfA, std::vector<Line_CS2D> linesOfB)
{
    std::vector<Intersection_CS2D> list;
    for (Line_CS2D loa : linesOfA) {
        for (Line_CS2D lob : linesOfB) {
            std::optional<Intersection_CS2D> is = lid.intersects(loa, lob);
            if (is.has_value()) {
                list.push_back(is.value());
            }
        }
    }
    return list;
}

/**
 * Note: The reason this method doesn't just use getPolygonIntersections and check whether
 * the size is over 0, is that we can aboard the loop as soon as a single intersection is found
 * here, which, when there are more intersections, will perform faster
 */
bool CollisionDetector_CS2D::doPolygonsIntersect(std::vector<Line_CS2D> linesOfA, std::vector<Line_CS2D> linesOfB)
{
    for (Line_CS2D loa : linesOfA) {
        for (Line_CS2D lob : linesOfB) {
            if (lid.intersects(loa, lob)) {
                return true;
            }
        }
    }
    return false;
}

std::vector<Intersection_CS2D> CollisionDetector_CS2D::getAabbIntersections(AABB_CS2D a, AABB_CS2D b)
{
    return getPolygonIntersections(a.splitIntoLines(), b.splitIntoLines());
}
