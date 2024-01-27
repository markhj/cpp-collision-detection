#ifndef COLLISION_DETECTION_DETECTOR_HPP
#define COLLISION_DETECTION_DETECTOR_HPP

#include <vector>

template <typename AABB_CSXD,
        typename Line_CSXD,
        typename Intersection_CSXD,
        typename glmVecX>
class CollisionDetector {
public:
    virtual bool hasLayerAndMaskIntersection(std::vector<int> aLayers,
                                             std::vector<int> aMasks,
                                             std::vector<int> bLayers,
                                             std::vector<int> bMasks) = 0;

    virtual bool aabbContainsPoint(AABB_CSXD aabb, glmVecX point) = 0;

    virtual bool aabbContainsAnyOf(AABB_CSXD aabb, std::vector<glmVecX> points) = 0;

    virtual bool aabbsOverlap(AABB_CSXD a, AABB_CSXD b) = 0;

    virtual std::vector<Intersection_CSXD> getAabbIntersections(AABB_CSXD a, AABB_CSXD b) = 0;

    virtual bool doPolygonsIntersect(std::vector<Line_CSXD> a, std::vector<Line_CSXD> b) = 0;

    virtual std::vector<Intersection_CSXD> getPolygonIntersections(std::vector<Line_CSXD> a, std::vector<Line_CSXD> b) = 0;

};

#endif
