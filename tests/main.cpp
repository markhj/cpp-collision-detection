#include <bbunit/bbunit.hpp>

#include "2d/aabb2d_gen.cpp"
#include "2d/collision-detection2d.cpp"
#include "2d/shape-2d-test.cpp"
#include "2d/aabb-2d-overlapping-test.cpp"
#include "2d/partition-2d-test.cpp"
#include "misc/layers-masks-test.cpp"
#include "misc/line-intersection-test.cpp"
#include "misc/calculate-bbox-test.cpp"

int main()
{
    BBUnit::TestSuite<LayersMasksTest> layersMasks(
            &LayersMasksTest::basics2D
            );

    BBUnit::TestSuite<LineIntersectionTest> lineIntersects(
            &LineIntersectionTest::intersects2D
    );

    BBUnit::TestSuite<AABB2D_Generation_Test> aabb2dGen(
            &AABB2D_Generation_Test::noTranslation,
            &AABB2D_Generation_Test::withTranslation,
            &AABB2D_Generation_Test::getAabbIntersections
            );

    BBUnit::TestSuite<AABB2DOverlappingTest> aabb2dOverlapping(
            &AABB2DOverlappingTest::translation
    );

    BBUnit::TestSuite<Shape2DTest> shape2d(
            &Shape2DTest::getLinesWithTransforms
    );

    BBUnit::TestSuite<CollisionDetection2DTest> collision2d(
            &CollisionDetection2DTest::aabbContainsPoint,
            &CollisionDetection2DTest::aabbContainsAnyOf,
            &CollisionDetection2DTest::polygonsOverlap,
            &CollisionDetection2DTest::polygonsOverlapRotation
            );

    BBUnit::TestSuite<CalculatesBoundingBoxesTest> calcBboxTest(
            &CalculatesBoundingBoxesTest::bbox2dLines
    );

    BBUnit::TestSuite<Partition2DTest> partition2DTest(
            &Partition2DTest::test,
            &Partition2DTest::global,
            &Partition2DTest::layersAndMasks
    );

    BBUnit::TestRunner().run(layersMasks,
                             lineIntersects,
                             aabb2dGen,
                             aabb2dOverlapping,
                             calcBboxTest,
                             shape2d,
                             collision2d,
                             partition2DTest
                             );

    return 0;
}
