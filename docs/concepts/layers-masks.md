# 📡 Layers and masks

The concept of **layers and masks** is inspired by Godot's
pendant.

Essentially, there are use-cases where we don't want *every* to object
to have collisions with *every* other object.

To solve this, we use layers and masks.

A **layer** is where an object itself resides.
The **mask** specifies the objects it can collide with.

So, it's possible for an object to reside in layer 1,
but only collide with objects residing in layer 2 (given that it has "2" as its mask).

> A shape can exist in multiple layers, and interact with multiple masks.

This is specific to every instance of a class based on ``CollisionShape``.

## Example
````c++
Rect_CS2D rect;

// This shape resides in layers 1 and 5
rect.layers = { 1, 5 };

// This shape can only collide with objects which are in layer 2
rect.masks = { 2 };
````
