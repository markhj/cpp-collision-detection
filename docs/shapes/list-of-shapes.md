# List of shapes

Here you find the list of [collision shapes](shapes.md).

## 2D
### Rectangle ◻️
````c++
explicit Rect_CS2D(glm::vec2 size)
````

Creates a rectangle with the specified size (length = x, height = y).
️
### Regular polygon 🔵
````c++
RegularPolygon_CS2D(unsigned int sides, double radius)
````
Creates a regular polygon with the specified number of sides and with
the specified radius.

This can, among other things, be used to approximate a circle.

