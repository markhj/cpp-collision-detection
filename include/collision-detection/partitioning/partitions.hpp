#ifndef COLLISION_DETECTION_PARTITIONS_HPP
#define COLLISION_DETECTION_PARTITIONS_HPP

#include <vector>

enum class Strategy {
    AABB,
    Polygon,
};

template <typename Shape_CSXD>
class Group_CSXD {
public:
    virtual void resume() = 0;

    virtual void pause() = 0;

    virtual bool isActive() = 0;

    virtual void addShape(Shape_CSXD* shape) = 0;

    virtual std::vector<Shape_CSXD*> getShapes() = 0;

    bool global = false;

protected:
    bool active = true;

    std::vector<Shape_CSXD*> shapes;

};

template <typename CollisionDetector_CSXD, typename Group_CSXD, typename Shape_CSXD, typename Collision_CSXD>
class World_CSXD {
public:
    virtual void addGroup(Group_CSXD* group) = 0;

    virtual std::vector<Collision_CSXD> detect() = 0;

protected:
    virtual std::vector<Shape_CSXD*> compileListOfShapes(Group_CSXD* group) = 0;

};

#endif
