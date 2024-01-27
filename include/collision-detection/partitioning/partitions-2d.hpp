#ifndef COLLISION_DETECTION_PARTITIONS_2D_HPP
#define COLLISION_DETECTION_PARTITIONS_2D_HPP

#include <utility>
#include <vector>
#include "collision-detection/detection/intersections.hpp"
#include "collision-detection/shapes/2d/shape-2d.hpp"
#include "collision-detection/detection/collisions.hpp"
#include "collision-detection/detection/collision-detector-2d.hpp"
#include "partitions.hpp"

class Group_CS2D : public Group_CSXD<Shape_CS2D> {
public:
    void resume() override;

    void pause() override;

    bool isActive() override;

    void addShape(Shape_CS2D* shape) override;

    std::vector<Shape_CS2D*> getShapes() override;

};

class World_CS2D : public World_CSXD<CollisionDetector_CS2D, Group_CS2D, Shape_CS2D, Collision_CS2D> {
public:
    explicit World_CS2D(CollisionDetector_CS2D* cd)
        : cd(cd), strategies({Strategy::AABB, Strategy::Polygon}) { }

    World_CS2D(CollisionDetector_CS2D* cd, std::vector<Strategy> strategies)
        : cd(cd), strategies(std::move(strategies)) { }

    void addGroup(Group_CS2D* group) override;

    std::vector<Collision_CS2D> detect() override;

protected:
    std::vector<Strategy> strategies;

    std::vector<Group_CS2D*> groups;

    CollisionDetector_CS2D* cd;

    std::vector<Shape_CS2D*> compileListOfShapes(Group_CS2D* group) override;

};

#endif
