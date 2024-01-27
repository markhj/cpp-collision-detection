#include "collision-detection/traits/id-generator.hpp"

unsigned int IdGenerator::id = 0;

unsigned int IdGenerator::generateId()
{
    id++;
    return id;
}
