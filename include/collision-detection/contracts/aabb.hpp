#ifndef COLLISION_DETECTION_AABB_HPP
#define COLLISION_DETECTION_AABB_HPP

#include <vector>

template <typename vecXD, typename Line_CSXD>
class AABB {
public:
    vecXD size, global_a, global_b;

    virtual std::vector<Line_CSXD> splitIntoLines() = 0;

};

#endif
