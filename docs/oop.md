## Object Oriented Programming

## Abstraction
> Method: Interface through `function pointers` and `header files`.

Abstraction in C can be achieved by creating "interfaces" with function pointers and only exposing necessary information in header files. This approach hides the implementation details, showing only what is essential to the user.

Example: Abstracting Shapes with a VTable Interface.

## Encapsulation
> Method: `Structs` with `functions` and `static` variables.

Encapsulation in C can be managed by using opaque pointers, static variables, and functions that operate only on data within a given scope. To hide the inner details of a struct, you can only expose a pointer to it without revealing its full structure.

### Access Control or Visibility
#### Public
#### Protected
#### Private

## Inheritance
> Method: Composition and containment.

Inheritance can be achieved by embedding one structure within another, allowing the "child" struct to contain data and functionality from the "parent" struct.

## Polymorphism
> Method: `Function pointers` in structs.

Polymorphism can be achieved by using function pointers in structs to dynamically determine which function should be called. This enables objects of different types to be handled through a common interface.
