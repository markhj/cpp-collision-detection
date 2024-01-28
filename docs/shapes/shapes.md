# 🔶 Shape basics

A **collision shape** is either an exact or approximated version of
a rendered shape, which is used to determine intersections.

In 2D, a shape consists of lines.

## ↩️ Global position and rotation
It's important to note that all objects are created at the center of the scene.
In other words, the center of an object starts at the center of the world.

To move and rotate, you need to apply transforms.

For this, you have two methods:

````c++
void translate(glm::vec2 value);
void rotate(double value);
````

### Example
This translates the center of the object to ``(1.0, 0.5)`` and
rotates it by 45&deg;

````c++
cs_rect.translate(glm::ved2(1.0, 0.5));
cs_rect.rotate(M_PI / 4.0);
````