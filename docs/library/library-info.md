# Notes about the library

## Naming convention
### Classes
Almost every class has one of these suffixes:

- ``_CSXD``: Used for contracts and base classes where a dimension-specific implementation is expected.
- ``_CS2D``: 2D-implementation
- ``_CS3D``: 3D-implementation

These suffixes are used to prevent name collisions (pun intended), but also
to make it more apparent which role a class has.

### Filenames

- Specific implementations are named with ``-2d`` and ``-3d`` in the filename.
- The files with classes corresponding to ``_CSXD`` are named simply by the class name.
- Files should not carry the dimension-specification if they exist only in one of the scopes. A rect(angle) is always 2D, a cube is always 3D.