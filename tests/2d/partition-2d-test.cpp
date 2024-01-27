#include <bbunit/bbunit.hpp>
#include "collision-detection/public.hpp"

class Partition2DTest : public BBUnit::TestCase {
public:
    void test()
    {
        CollisionDetector_CS2D cd;
        Rect_CS2D a({ 1.0, 1.0 });
        Rect_CS2D b({ 1.0, 1.0 });

        b.translate({ 0.5, 0.5 });

        World_CS2D world(&cd);

        Group_CS2D group;
        group.addShape(&a);
        group.addShape(&b);

        world.addGroup(&group);

        std::vector<Collision_CS2D> collisions = world.detect();

        assertCount(1, collisions);
        assertEquals(static_cast<int>(a.getId()), collisions[0].shapes[0]->getId());
        assertEquals(static_cast<int>(b.getId()), collisions[0].shapes[1]->getId());

        std::vector<Intersection_CS2D> intersections = collisions[0].intersections;
        assertCount(2, intersections);
        assertEquals(0.0, intersections[0].point.x);
        assertEquals(0.5, intersections[0].point.y);
        assertEquals(0.5, intersections[1].point.x);
        assertEquals(0.0, intersections[1].point.y);
    }

    void global()
    {
        CollisionDetector_CS2D cd;
        Rect_CS2D a({ 1.0, 1.0 });
        Rect_CS2D b({ 1.0, 1.0 });

        b.translate({ 0.5, 0.5 });

        World_CS2D world(&cd);

        Group_CS2D groupA, groupB;
        groupA.addShape(&a);
        groupB.addShape(&b);

        world.addGroup(&groupA);
        world.addGroup(&groupB);

        assertCount(0, world.detect());

        groupA.global = true;
        assertCount(1, world.detect());
    }

    void layersAndMasks()
    {
        CollisionDetector_CS2D cd;
        Rect_CS2D a({ 1.0, 1.0 });
        Rect_CS2D b({ 1.0, 1.0 });

        b.translate({ 0.5, 0.5 });

        World_CS2D world(&cd);

        Group_CS2D group;
        group.addShape(&a);
        group.addShape(&b);

        world.addGroup(&group);

        assertCount(1, world.detect());

        a.layers = { 3 };
        a.masks = { 2 };

        assertCount(0, world.detect());
    }

};
