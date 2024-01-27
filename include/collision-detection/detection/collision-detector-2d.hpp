#ifndef COLLISION_DETECTION_DETECTOR2D_HPP
#define COLLISION_DETECTION_DETECTOR2D_HPP

#include "collision-detection/contracts/collision-detector.hpp"
#include "collision-detection/traits/processes-layers-masks.hpp"
#include "collision-detection/shapes/2d/shape-2d.hpp"
#include "line-intersection.hpp"
#include "intersections.hpp"

class CollisionDetector_CS2D :
        public CollisionDetector<AABB_CS2D, Line_CS2D, Intersection_CS2D, glm::vec2>,
        ProcessesLayersAndMasks {
public:
    CollisionDetector_CS2D() : lid(LineIntersectionDetector()) { }

    bool hasLayerAndMaskIntersection(std::vector<int> aLayers,
                                     std::vector<int> aMasks,
                                     std::vector<int> bLayers,
                                     std::vector<int> bMasks) override;

    bool aabbContainsPoint(AABB_CS2D aabb, glm::vec2 point) override;

    bool aabbContainsAnyOf(AABB_CS2D aabb, std::vector<glm::vec2> points) override;

    bool aabbsOverlap(AABB_CS2D a, AABB_CS2D b) override;

    std::vector<Intersection_CS2D> getAabbIntersections(AABB_CS2D a, AABB_CS2D b) override;

    bool doPolygonsIntersect(std::vector<Line_CS2D> a, std::vector<Line_CS2D> b) override;

    std::vector<Intersection_CS2D> getPolygonIntersections(
            std::vector<Line_CS2D> linesOfA,
            std::vector<Line_CS2D> linesOfB) final;

private:
    LineIntersectionDetector lid;

};

#endif
