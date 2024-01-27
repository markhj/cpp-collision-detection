#include <bbunit/bbunit.hpp>
#include "collision-detection/public.hpp"

class Bbox2DLines : public CalculatesBoundingBoxes {
public:
    static glm::vec2 calc(const std::vector<Line_CS2D>& lines)
    {
        return calculateBounds(lines);
    }

};

class CalculatesBoundingBoxesTest : public BBUnit::TestCase {
public:
    void bbox2dLines()
    {
        std::vector<Line_CS2D> lines {
            Line_CS2D { {0.0, 0.0}, {1.0, 1.0} },
            Line_CS2D { {-1.5, -2.0}, {2.0, 1.0} },
        };

        glm::vec2 result = Bbox2DLines::calc(lines);

        assertEquals(3.5, result.x);
        assertEquals(3.0, result.y);
    }

};
