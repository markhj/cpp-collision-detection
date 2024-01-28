# ▶️ Pausing and resuming groups

When there's no activity in a group, you can pause it,
such that it will be skipped during a calculation of collisions.
This is a great way to enchance performance in complex worlds
with many objects.

## Methods
````c++
void resume();
void pause();
bool isActive();
````

### Example
````c++
Group_CS2D a;

// Group will not be included in collision calculations
a.pause();

// Now, it will
a.resume();
````