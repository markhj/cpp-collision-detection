#include <bbunit/bbunit.hpp>
#include "collision-detection/public.hpp"

class AABB2D_Generation_Test : public BBUnit::TestCase {
public:
    void noTranslation()
    {
        AABB_CS2D aabb = Rect_CS2D(glm::vec2(2.0, 1.0)).getAABBWithoutTransforms();

        assertEquals(2.0, aabb.size.x, "AABB (without transforms) size.x");
        assertEquals(1.0, aabb.size.y, "AABB (without transforms) size.y");

        assertEquals(-1.0, aabb.global_a.x, "AABB (without transforms) global_a.x");
        assertEquals(-0.5, aabb.global_a.y, "AABB (without transforms) global_a.y");

        assertEquals(1.0, aabb.global_b.x, "AABB (without transforms) global_b.x");
        assertEquals(0.5, aabb.global_b.y, "AABB (without transforms) global_b.y");
    }

    void withTranslation()
    {
        Rect_CS2D rect(glm::vec2(2.0, 1.0));
        rect.translate(glm::vec2(3.0, 1.0));
        AABB_CS2D aabb = rect.getAABBWithTransforms();

        assertEquals(2.0, aabb.size.x, "AABB (translations) size.x");
        assertEquals(1.0, aabb.size.y, "AABB (translations) size.y");

        assertEquals(-1.0 + 3.0, aabb.global_a.x, "AABB (translations) global_a.x");
        assertEquals(-0.5 + 1.0, aabb.global_a.y, "AABB (translations) global_a.y");

        assertEquals(1.0 + 3.0, aabb.global_b.x, "AABB (translations) global_b.x");
        assertEquals(0.5 + 1.0, aabb.global_b.y, "AABB (translations) global_b.y");
    }

    void getAabbIntersections()
    {
        // Use a Rect to create two AABBs
        Rect_CS2D rect(glm::vec2(2.0, 1.0));

        rect.translate(glm::vec2(3.0, 1.0));
        AABB_CS2D a = rect.getAABBWithTransforms();

        rect.translate(glm::vec2(2.0, 0.5));
        AABB_CS2D b = rect.getAABBWithTransforms();

        auto intersections = CollisionDetector_CS2D().getAabbIntersections(a, b);

        assertCount(2, intersections);
        assertEquals(2.0, intersections[0].point.x);
        assertEquals(1.0, intersections[0].point.y);
        assertEquals(3.0, intersections[1].point.x);
        assertEquals(0.5, intersections[1].point.y);
    }

};
