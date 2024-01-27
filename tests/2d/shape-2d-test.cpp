#include <bbunit/bbunit.hpp>
#include "collision-detection/public.hpp"

class Shape2DTest : public BBUnit::TestCase {
public:
    void getLinesWithTransforms()
    {
        Rect_CS2D rect(glm::vec2(2.0));
        rect.translate(glm::vec2(10.0, 5.0));

        std::vector<Line_CS2D> lines = rect.getLinesWithTransforms();

        // Check the left line
        assertEquals(9.0, lines[0].a.x);
        assertEquals(4.0, lines[0].a.y);
        assertEquals(9.0, lines[0].b.x);
        assertEquals(6.0, lines[0].b.y);

        // Check the top line
        assertEquals(9.0, lines[1].a.x);
        assertEquals(6.0, lines[1].a.y);
        assertEquals(11.0, lines[1].b.x);
        assertEquals(6.0, lines[1].b.y);
    }

};
