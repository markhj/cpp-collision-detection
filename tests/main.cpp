#include <bbunit/bbunit.hpp>

#include "2d/aabb2d-test.cpp"
#include "2d/collision-detection-2d-test.cpp"
#include "2d/shape-2d-test.cpp"
#include "2d/aabb-2d-overlapping-test.cpp"
#include "2d/partition-2d-test.cpp"
#include "misc/line-intersection-test.cpp"
#include "misc/calculate-bbox-test.cpp"

int main()
{
    BBUnit::TestSuite<LineIntersectionTest> lineIntersectionTest(
            &LineIntersectionTest::intersects2D
    );

    BBUnit::TestSuite<AABB2D_Generation_Test> aabb2dTest(
            &AABB2D_Generation_Test::noTranslation,
            &AABB2D_Generation_Test::withTranslation,
            &AABB2D_Generation_Test::getAabbIntersections
            );

    BBUnit::TestSuite<AABB2DOverlappingTest> aabb2dOverlappingTest(
            &AABB2DOverlappingTest::translation
    );

    BBUnit::TestSuite<Shape2DTest> shape2dTest(
            &Shape2DTest::getLinesWithTransforms
    );

    BBUnit::TestSuite<CollisionDetection2DTest> collision2dTest(
            &CollisionDetection2DTest::aabbContainsPoint,
            &CollisionDetection2DTest::aabbContainsAnyOf,
            &CollisionDetection2DTest::polygonsOverlap,
            &CollisionDetection2DTest::polygonsOverlapRotation
            );

    BBUnit::TestSuite<CalculatesBoundingBoxesTest> calculatesBoundingBoxTest(
            &CalculatesBoundingBoxesTest::bbox2dLines
    );

    BBUnit::TestSuite<Partition2DTest> partition2dTest(
            &Partition2DTest::test,
            &Partition2DTest::global,
            &Partition2DTest::layersAndMasks
    );

    BBUnit::TestRunner().run(lineIntersectionTest,
                             aabb2dTest,
                             aabb2dOverlappingTest,
                             calculatesBoundingBoxTest,
                             shape2dTest,
                             collision2dTest,
                             partition2dTest
                             );

    return 0;
}
