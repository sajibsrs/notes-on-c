# Polymorphism
> Method: `Function pointers` in structs.

Polymorphism can be achieved by using function pointers in structs to dynamically determine which function should be called. This enables objects of different types to be handled through a common interface.

shape.h

Defines a base Shape struct with a function pointer table (vtable) for area calculation and printing. This serves as an "interface" for derived shapes.

```c
#ifndef SHAPE_H
#define SHAPE_H

// Forward declaration of Shape struct
typedef struct Shape Shape;

// VTable struct for Shape containing function pointers for polymorphic behavior
typedef struct {
  float (*area)(Shape *self);   // Function pointer for area calculation
  void (*print)(Shape *self);   // Function pointer for printing
} ShapeVTable;

// Base Shape struct with a pointer to its vtable
struct Shape {
  ShapeVTable *vtable;  // Pointer to function table for polymorphism
};

// Function declarations for calling the vtable functions
float shape_area(Shape *shape);
void shape_print(Shape *shape);

#endif
```

shape.c

Implements functions to access the polymorphic functions in the vtable.
```c
#include "shape.h"

// Calls the appropriate area function based on the vtable
float shape_area(Shape *shape) {
    return shape->vtable->area(shape);
}

// Calls the appropriate print function based on the vtable
void shape_print(Shape *shape) {
    shape->vtable->print(shape);
}
```

circle.h

Defines a Circle struct that includes Shape as its base and declares functions for creating and destroying a Circle.
```c
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// Circle struct inheriting Shape and adding radius attribute
typedef struct {
  Shape base;     // Base Shape struct
  float radius;   // Circle-specific attribute
} Circle;

// Function declarations for Circle
Circle *circle_create(float radius);  // Create a Circle instance
void circle_destroy(Circle *circle);  // Destroy a Circle instance

#endif
```

circle.c

Implements the specific functions for Circle, including its area calculation and printing behavior.
```c
#include "circle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Circle-specific area calculation
static float circle_area(Shape *shape) {
  Circle *circle = (Circle *)shape;  // Cast to Circle
  return M_PI * circle->radius * circle->radius;
}

// Circle-specific print function
static void circle_print(Shape *shape) {
  Circle *circle = (Circle *)shape;
  printf("Circle with radius: %.2f\n", circle->radius);
}

// Define the vtable for Circle with its specific functions
static ShapeVTable circle_vtable = {
  .area = circle_area,
  .print = circle_print,
};

// Function to create a Circle and assign the vtable
Circle *circle_create(float radius) {
  Circle *circle = malloc(sizeof(Circle));
  circle->base.vtable = &circle_vtable;  // Set Circle vtable
  circle->radius = radius;
  return circle;
}

// Free allocated memory for Circle
void circle_destroy(Circle *circle) {
  free(circle);
}
```

rectangle.h

Defines a Rectangle struct that includes Shape as its base and declares functions for creating and destroying a Rectangle.
```c
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

// Rectangle struct inheriting Shape and adding width, height attributes
typedef struct {
  Shape base;        // Base Shape struct
  float width;       // Rectangle-specific attribute
  float height;      // Rectangle-specific attribute
} Rectangle;

// Function declarations for Rectangle
Rectangle *rectangle_create(float width, float height);  // Create a Rectangle instance
void rectangle_destroy(Rectangle *rectangle);            // Destroy a Rectangle instance

#endif
```

rectangle.c

Implements the specific functions for Rectangle, including its area calculation and printing behavior.
```c
#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

// Rectangle-specific area calculation
static float rectangle_area(Shape *shape) {
  Rectangle *rect = (Rectangle *)shape;  // Cast to Rectangle
  return rect->width * rect->height;
}

// Rectangle-specific print function
static void rectangle_print(Shape *shape) {
  Rectangle *rect = (Rectangle *)shape;
  printf("Rectangle with width: %.2f and height: %.2f\n", rect->width, rect->height);
}

// Define the vtable for Rectangle with its specific functions
static ShapeVTable rectangle_vtable = {
    .area = rectangle_area,
    .print = rectangle_print,
};

// Function to create a Rectangle and assign the vtable
Rectangle *rectangle_create(float width, float height) {
  Rectangle *rect = malloc(sizeof(Rectangle));
  rect->base.vtable = &rectangle_vtable;  // Set Rectangle vtable
  rect->width = width;
  rect->height = height;
  return rect;
}

// Free allocated memory for Rectangle
void rectangle_destroy(Rectangle *rect) {
  free(rect);
}
```

Usage:
```c
#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include <stdio.h>

int main(void) {
  Shape *shapes[2];

  // Create and add a Rectangle to the shapes array
  shapes[0] = (Shape *)rectangle_create(4.0f, 3.0f);

  // Create and add a Circle to the shapes array
  shapes[1] = (Shape *)circle_create(5.0f);

  // Iterate through shapes and use polymorphic functions
  for (int i = 0; i < 2; i++) {
    printf("Area: %.2f\n", shape_area(shapes[i]));
    shape_print(shapes[i]);
  }

  // Clean up memory
  rectangle_destroy((Rectangle *)shapes[0]);
  circle_destroy((Circle *)shapes[1]);

  return 0;
}
```

Output:
```plaintext
Area: 12.00
Rectangle with width: 4.00 and height: 3.00
Area: 78.54
Circle with radius: 5.00
```
