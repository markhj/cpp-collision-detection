# 💥 Working without partitions

Although it's recommended, you're not required to use the concepts
of [world and groups](../tutorials/how-it-works.md).

You can retrieve intersections directly by using
the ``CollisionDetector``.

Start by instantiating the 2D collision detector:

````c++
CollisionDetector_CS2D cd;
````

Next, we extract vectors with lines of the two shapes,
where we want to calculate intersections.

````c++
std::vector<Line_CS2D> a = shapeA.getLinesWithTransforms();
std::vector<Line_CS2D> b = shapeB.getLinesWithTransforms();
````

> ⚠️ It's important to use the ``getLinesWithTransforms`` as you otherwise
> get the lines of the shapes where the shape is positioned at the scene center.

Now, you can iterate over the intersections and do what you need to
do with them.

````c++
std::vector<Intersection_CS2D> intersections = cd.getPolygonIntersections(a, b);
for (const Intersection_CS2D& c : intersections) {
    // Intersection point is contained in c.point (glm::vec2)
}
````

> Remember that [intersections](../concepts/intersections-collisions.md) are given in global coordinates.
