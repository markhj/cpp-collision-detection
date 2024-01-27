#include <bbunit/bbunit.hpp>
#include <cmath>
#include "collision-detection/public.hpp"

class CollisionDetection2DTest : public BBUnit::TestCase {
public:
    void aabbContainsPoint()
    {
        CollisionDetector_CS2D cd;
        AABB_CS2D aabb;
        aabb.global_a = glm::vec2(-1.0, -0.5);
        aabb.global_b = glm::vec2(1.0, 0.5);

        assertTrue(cd.aabbContainsPoint(aabb, glm::vec2(0.0)));

        // Must be true when exactly on the edges
        assertTrue(cd.aabbContainsPoint(aabb, glm::vec2(-1.0, -0.5)));
        assertTrue(cd.aabbContainsPoint(aabb, glm::vec2(1.0, 0.5)));

        // X-coordinate outside
        assertFalse(cd.aabbContainsPoint(aabb, glm::vec2(-1.1, 0.0)));
        assertFalse(cd.aabbContainsPoint(aabb, glm::vec2(1.1, 0.0)));

        // Y-coordinate outside
        assertFalse(cd.aabbContainsPoint(aabb, glm::vec2(0.0, -0.6)));
        assertFalse(cd.aabbContainsPoint(aabb, glm::vec2(0.0, 0.6)));

        // Both coordinates outside
        assertFalse(cd.aabbContainsPoint(aabb, glm::vec2(-1.1, -0.6)));
    }

    void aabbContainsAnyOf()
    {
        CollisionDetector_CS2D cd;
        AABB_CS2D aabb;
        aabb.global_a = glm::vec2(-1.0, -0.5);
        aabb.global_b = glm::vec2(1.0, 0.5);

        std::vector<glm::vec2> listA = {
                glm::vec2(0.0),
                glm::vec2(2.0),
        };

        std::vector<glm::vec2> listB = {
                glm::vec2(3.0),
                glm::vec2(2.0),
        };

        assertTrue(cd.aabbContainsAnyOf(aabb, listA));
        assertFalse(cd.aabbContainsAnyOf(aabb, listB));
    }

    void polygonsOverlap()
    {
        CollisionDetector_CS2D cd;
        Rect_CS2D a(glm::vec2(1.0)), b({2.0, 1.0});

        assertTrue(cd.doPolygonsIntersect(a.getLinesWithTransforms(), b.getLinesWithTransforms()));

        b.translate(glm::vec2(10.0));

        assertFalse(cd.doPolygonsIntersect(a.getLinesWithTransforms(), b.getLinesWithTransforms()));
    }

    void polygonsOverlapRotation()
    {
        CollisionDetector_CS2D cd;
        Rect_CS2D a(glm::vec2(1.0)), b({2.0, 0.1});

        assertTrue(cd.doPolygonsIntersect(a.getLinesWithTransforms(), b.getLinesWithTransforms()));

        b.translate(glm::vec2(0.9, 0.0));
        assertTrue(
                cd.doPolygonsIntersect(a.getLinesWithTransforms(), b.getLinesWithTransforms()),
                "Polygon translation");

        b.rotate(M_PI / 2.0);
        assertFalse(
                cd.doPolygonsIntersect(a.getLinesWithTransforms(), b.getLinesWithTransforms()),
                "Polygon rotation");
    }

};
