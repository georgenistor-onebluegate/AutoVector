# Dynamic AutoVector - no resizing
**Author:** George Nistor  
**Version:** 1.0

This is an AutoVector utility which does not require resize with re-copy of the elements and creation of a new buffer.
Instead it manages a list of dynamically allocated buffers.

- main advantage : no resize
- fast access by index


The utility was tested on Linux with CLion.
