# 🔬 How it works

**Collision Detection for C++** is designed around the idea of
separating the rendered world from collision calculation.

It should be possible to render objects in the far distance, without involving
them in the collision calculations.

In other words, there's a "collision world" and a "rendered world" which
exist in parallel.

This allows us to partition the "collision world" into smaller sections,
for instance the area or a room a player is inside. There's often no reason
to waste precious performance on calculating collisions on a far-away hill, or often,
even in the neighbouring room.

To achieve this, you start by creating a "world". In this world, you add "groups".
Every group contains a set number of "shapes". Then you can enable and disable
groups on a per-need basis.

When you run the method to detect collisions, you will be provided a vector
with information about collisions detected in active groups.
