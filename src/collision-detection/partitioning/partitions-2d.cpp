#include <iostream>
#include <algorithm>
#include "collision-detection/partitioning/partitions-2d.hpp"

void World_CS2D::addGroup(Group_CS2D *group)
{
    groups.push_back(group);
}

std::vector<Shape_CS2D *> World_CS2D::compileListOfShapes(Group_CS2D* group)
{
    std::vector<Shape_CS2D *> list = group->getShapes();

    for (Group_CS2D* otherGroup : groups) {
        if (!otherGroup->global) {
            continue;
        }

        for (Shape_CS2D* shape : otherGroup->getShapes()) {
            bool found = false;
            for (Shape_CS2D* otherShape : list) {
                if (otherShape->getId() == shape->getId()) {
                    found = true;
                }
            }
            if (!found) {
                list.push_back(shape);
            }
        }
    }

    return list;
}

std::vector<Collision_CS2D> World_CS2D::detect()
{
    std::vector<Collision_CS2D> list;

    for (Group_CS2D* group : groups) {
        if (!group->isActive()) {
            continue;
        }
        std::vector<std::pair<unsigned int, unsigned int>> paired;
        std::vector<Shape_CS2D*> shapes = compileListOfShapes(group);
        for (Shape_CS2D* a : shapes) {
            for (Shape_CS2D* b : shapes) {
                if (a->getId() == b->getId()) {
                    continue;
                } else if (!cd->hasLayerAndMaskIntersection(a->layers, a->masks, b->layers, b->masks)) {
                    continue;
                }

                std::pair<unsigned int, unsigned int> pair;
                if (a->getId() < b->getId()) {
                    pair = {a->getId(), b->getId()};
                } else {
                    pair = {b->getId(), a->getId()};
                }

                bool found = false;
                for (auto compare : paired) {
                    if (compare == pair) {
                        found = true;
                    }
                }

                if (found) {
                    continue;
                }

                paired.push_back(pair);

                std::optional<std::vector<Intersection_CS2D>> intersections = std::nullopt;

                // Our strategy is to assume there's a collision, until disproven
                // This allows us to iterate through some simple initial tests, which
                // are lighter performance-wise.
                bool assumedCollision = true;
                for (Strategy strategy : strategies) {
                    switch (strategy) {
                        case Strategy::AABB:
                            intersections = cd->getAabbIntersections(
                                    a->getAABBWithTransforms(),
                                    b->getAABBWithTransforms()
                            );
                            break;
                        case Strategy::Polygon:
                            intersections = cd->getPolygonIntersections(
                                    a->getLinesWithTransforms(),
                                    b->getLinesWithTransforms()
                            );
                            break;
                    }

                    if (intersections.has_value() && intersections.value().empty()) {
                        assumedCollision = false;
                        break;
                    }
                }

                if (assumedCollision && intersections.has_value()) {
                    Collision_CS2D collision;
                    collision.intersections = intersections.value();
                    collision.shapes = { a, b };
                    list.push_back(collision);
                }
            }
        }
    }

    return list;
}

void Group_CS2D::resume()
{
    active = true;
}

void Group_CS2D::pause()
{
    active = false;
}

void Group_CS2D::addShape(Shape_CS2D *shape)
{
    shapes.push_back(shape);
}

bool Group_CS2D::isActive()
{
    return active;
}

std::vector<Shape_CS2D *> Group_CS2D::getShapes()
{
    return shapes;
}
