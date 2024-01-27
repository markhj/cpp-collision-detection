#include <bbunit/bbunit.hpp>
#include "collision-detection/public.hpp"

class AABB2DOverlappingTest : public BBUnit::TestCase {
public:
    void translation()
    {
        CollisionDetector_CS2D cd;
        Rect_CS2D a({1.0, 1.0}), b({1.0, 1.0});

        assertTrue(cd.aabbsOverlap(a.getAABBWithTransforms(), b.getAABBWithTransforms()));

        // Translation where the AABBs still overlap
        b.translate({ 0.5, 0.5 });
        assertTrue(cd.aabbsOverlap(a.getAABBWithTransforms(), b.getAABBWithTransforms()));

        // Translation where the AABBs intersect exactly on the edge
        b.translate({ 1.0, 1.0 });
        assertTrue(cd.aabbsOverlap(a.getAABBWithTransforms(), b.getAABBWithTransforms()));

        // AABBs don't overlap
        b.translate({ 1.1, 1.0 });
        assertFalse(cd.aabbsOverlap(a.getAABBWithTransforms(), b.getAABBWithTransforms()));
    }

};
