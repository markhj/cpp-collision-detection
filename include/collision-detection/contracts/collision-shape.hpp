#ifndef COLLISION_DETECTION_COLLISION_SHAPE_HPP
#define COLLISION_DETECTION_COLLISION_SHAPE_HPP

#include "aabb.hpp"
#include <vector>
#include <optional>

template <typename vecXD,
        typename rotationXD,
        typename AABB_CSXD,
        typename Line_CSXD>
class CollisionShape {
public:
    virtual void translate(vecXD value) = 0;

    virtual void rotate(rotationXD value) = 0;

    virtual AABB_CSXD getAABBWithoutTransforms() = 0;

    virtual AABB_CSXD getAABBWithTransforms() = 0;

    virtual std::vector<Line_CSXD> getLinesWithoutTransforms() = 0;

    virtual std::vector<Line_CSXD> getLinesWithTransforms() = 0;

    virtual unsigned int getId() = 0;

    std::vector<int> layers = {1};

    std::vector<int> masks = {1};

protected:
    std::optional<unsigned int> id;

    vecXD translation;

    rotationXD rotation;

};

#endif
