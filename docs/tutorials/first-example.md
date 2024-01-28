# 🎳 First example

In this example we will learn:

*   How to set up the "collision world"
*   How to create groups and shapes
*   How to detect collisions

## 🌎 World, groups and shapes

We start off by creating instances of ``World_CS2D`` and
``Group_CS2D``, and connecting them.

But before anything else, we have to instantiate a collision detector,
because it must be injected into the world instance.

````c++
CollisionDetector_CS2D cd;

World_CS2D world(&cd);
Group_CS2D group;

world.addGroup(&group);
````

Now the world exists, and a group is added to it.

## 🔶 Adding shapes
Next up, we create two rectangles and add them to the group.

````c++
Rect_CS2D a(glm::vec2(1.0, 0.5)),
          b(glm::vec2(0.5, 3.0));

group.addShape(&a);
group.addShape(&b);
````

You can see all shapes under [List of shapes](../shapes/list-of-shapes.md).

## 🚦 Animating
To make this just a little bit interesting, we need to move the shapes around.

It's important to note that all shapes are created at the center of the scene. You'll
have to translate them together with their rendered visual counterparts.
Read more under [Shape basics](../shapes/shapes.md).

In this example, we're assuming you have some kind of rendering loop.

````c++
while (renderLoopRunning) {
    float delta = functionYouWroteToRetrieveDelta();
    
    a.translate(glm::vec2(sin(t) * 2.0, 0.0));
}
````

The first shape should now move back and forth on the X-axis.

## 🙊 Detecting collisions
You retrieve a vector of collisions by calling the ``world``'s ``detect`` method:

````c++
std::vector<Collision_CS2D> collisions = world.detect();
````

You can iterate over the collisions to extract intersections:

````c++
std::vector<Collision_CS2D> collisions = world.detect();
for (const Collision_CS2D& collision : collisions) {
    for (const Intersection_CS2D& intersection : collision.intersections) {
        std::cout << "Collision at (" << intersection.point.x << ", " << intersection.point.y << ")" << std::endl; 
    }
}
````

> Note that collisions will *only* be calculated between
> shapes in the same group, except for [global groups](../concepts/global-groups.md).
