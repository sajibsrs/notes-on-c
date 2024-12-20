# Abstraction
> Method: Interface through `function pointers` and `header files`.

Abstraction in C can be achieved by creating "interfaces" with function pointers and only exposing necessary information in header files. This approach hides the implementation details, showing only what is essential to the user.

---
**shape.h**

Defines a base structure for shapes and a "virtual table" (vtable) to store function pointers. Only necessary details are exposed here.

```c
#ifndef SHAPE_H
#define SHAPE_H

// Forward declaration of Shape and its virtual table (VTable)
typedef struct Shape Shape;
typedef struct ShapeVTable ShapeVTable;

// VTable for Shape: function pointers for area and draw methods
struct ShapeVTable {
    float (*area)(Shape *self);  // Calculates the area
    void (*draw)(Shape *self);   // Draws the shape
};

// Shape structure with a pointer to its VTable
struct Shape {
    ShapeVTable *vtable;  // Pointer to shape's virtual table
};

// Public interface functions
float shape_area(Shape *shape);  // Calls the area function in the vtable
void shape_draw(Shape *shape);   // Calls the draw function in the vtable

#endif
```

---
**shape.c**

Implements the public functions for shapes. These functions rely on function pointers in the vtable to determine behavior, abstracting details from the user.

```c
#include "shape.h"

// Call the area function from the shape's vtable
float shape_area(Shape *shape) {
    return shape->vtable->area(shape);
}

// Call the draw function from the shape's vtable
void shape_draw(Shape *shape) {
    shape->vtable->draw(shape);
}
```

---
**circle.h**

Defines the Circle structure, which includes the base Shape struct and specific data for circles. This file also provides a public interface for creating circles.

```c
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// Circle structure inheriting from Shape
typedef struct {
    Shape base;     // Base Shape struct
    float radius;   // Circle-specific data
} Circle;

Circle *circle_create(float radius);  // Constructor for Circle

#endif
```
___
**circle.c**

Implements the circle-specific functions and defines a vtable with function pointers for area and draw operations.

```c
#include "circle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the area of a circle
static float circle_area(Shape *shape) {
    Circle *circle = (Circle *)shape;  // Cast Shape to Circle
    return M_PI * circle->radius * circle->radius;
}

// Function to draw a circle
static void circle_draw(Shape *shape) {
    Circle *circle = (Circle *)shape;  // Cast Shape to Circle
    printf("Drawing Circle with radius: %.2f\n", circle->radius);
}

// Define the vtable for Circle, associating function pointers
static ShapeVTable circle_vtable = {
    .area = circle_area,
    .draw = circle_draw,
};

// Constructor for Circle
Circle *circle_create(float radius) {
    Circle *circle = malloc(sizeof(Circle));
    circle->base.vtable = &circle_vtable;  // Set vtable for Circle
    circle->radius = radius;

    return circle;
}

void circle_destroy(Circle *circle) {
    free(circle);  // Free allocated memory
}
```

---
***Usage:***

```c
#include "circle.h"
#include "shape.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Shape *circle = (Shape *)circle_create(5.0f);   // Create a Circle as a Shape

    printf("Circle area: %.2f\n", shape_area(circle));
    shape_draw(circle);

    // Cleanup
    free(circle);

    return 0;
}
```

**Output**
```plaintext
Circle area: 78.54
Drawing Circle with radius: 5.00
```
