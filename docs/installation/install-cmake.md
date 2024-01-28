# Install with CMake  🚧
Clone the repo to a location on your machine.
It technically doesn't matter where you put it, but to keep
things organized you can put it in a shared project or library directory.

````bash
git clone https://github.com/markhj/cpp-collision-detection
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
