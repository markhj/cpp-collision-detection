#include <bbunit/bbunit.hpp>
#include "collision-detection/public.hpp"

class LineIntersectionTest : public BBUnit::TestCase {
public:
    LineIntersectionTest() : lid(LineIntersectionDetector()) {}

    void intersects2D()
    {
        Line_CS2D a = create2DLine({0.0, 0.0}, {0.0, 1.0});
        Line_CS2D b = create2DLine({-0.5, 0.5}, {0.5, 0.5});
        Line_CS2D c = create2DLine({-0.5, -0.5}, {0.5, -0.5});
        Line_CS2D d = create2DLine({0.0, 0.5}, {0.5, 0.5});

        assertTrue(lid.intersects(a, b).has_value());
        assertFalse(lid.intersects(a, c).has_value());

        // A line that only overlap on an infinitely small point
        assertTrue(lid.intersects(a, d).has_value());

        // Lines that run in parallel
        assertFalse(lid.intersects(b, c).has_value());
    }

private:
    static Line_CS2D create2DLine(glm::vec2 a, glm::vec2 b)
    {
        return {
            .a = a,
            .b = b,
        };
    }

    LineIntersectionDetector lid;

};
