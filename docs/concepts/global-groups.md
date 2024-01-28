# 🌍 Global groups

Some objects aren't logically restricted to a single group.
This is usually true for the player, projectiles (such as gun shots), etc.

To solve this, you can make a group global.

````c++
Group_CS2D group;
group.global = true;
````

This means that the shapes in this particular group will be checked for collisions in all
active groups, and not just within itself. 
