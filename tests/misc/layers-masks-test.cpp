#include <bbunit/bbunit.hpp>
#include <utility>
#include "collision-detection/public.hpp"

class LayersMasksTest : public BBUnit::TestCase {
public:
    LayersMasksTest() : cd2D(CollisionDetector_CS2D()) { }

    void basics2D()
    {

    }

private:
    CollisionDetector_CS2D cd2D;

};
