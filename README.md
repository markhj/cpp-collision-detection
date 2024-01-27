![Project Image](https://res.cloudinary.com/drfztvfdh/image/upload/v1706348147/Github/Collision_detection_hmgqnl.jpg)

This library provides a number of tools for **collision detection** in 2D and 3D spaces.

It's a source library, which means it compiles together with your client project.

# Features 🌿
- Easy integration with graphics, physics and game engines
- Convex collision shapes
- Layers and masks
- World partitioning
- Detection strategy

# Upcoming features
- 3D support
- Concave collision shapes
- Refine architecture decisions

# Requirements
- Targeted at C++ 20
- GLM (OpenGL Math Library) discoverable via CMake's ``find_package``

# Installation
Clone the repo to a location on your machine:

````bash
git clone https://github.com/markhj/collision-detection
````

Add an environment variable readable by CMake: ``collision_detection_DIR`` which points to the location where you cloned the repo

In your ``CMakeLists.txt`` file add:

````cmake
find_package(collision_detection REQUIRED)
````

Additionally, you'll have to target the library on the executables/library where you want to use it. For example:

````cmake
target_link_libraries(my_app PRIVATE collision_detection)
````

If everything is correctly set up, you can now rebuild your CMake with a positive outcome.

# Time to code!
## Include
First, you have to include Collision Detect. You can pick out each individual header file which is relevant,
or you can just use the public header file:

````cmake
#include <collision-detection-detection/public.hpp>
````

This provides instant access to all classes in the Collision Detection library.

## Simple example
_Coming soon_

# Naming convention
## Classes
Almost every class has one of these suffixes:

- ``_CSXD``: Used for contracts and base classes where a dimension-specific implementation is expected.
- ``_CS2D``: 2D-implementation
- ``_CS3D``: 3D-implementation

These suffixes are used to prevent name collisions (pun intended), but also
to make it more apparent which role a class has.

## Filenames

- Specific implementations are named with ``-2d`` and ``-3d`` in the filename.
- The files with classes corresponding to ``_CSXD`` are named simply by the class name.
- Files should not carry the dimension-specification if they exist only in one of the scopes. A rect(angle) is always 2D, a cube is always 3D.