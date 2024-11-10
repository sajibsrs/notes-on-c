## Object Oriented Programming

## Abstraction
> Method: Interface through `function pointers` and `header files`.

Abstraction in C can be achieved by creating "interfaces" with function pointers and only exposing necessary information in header files. This approach hides the implementation details, showing only what is essential to the user.

**shape.h**
```c
#ifndef SHAPE_H
#define SHAPE_H

typedef struct Shape Shape;
typedef struct ShapeVTable ShapeVTable; // Shape virtual table.

struct ShapeVTable {
  float (*area)(Shape *self);
  void (*draw)(Shape *self);
};

struct Shape {
  ShapeVTable *vtable;
};

float shape_area(Shape *shape);
void shape_draw(Shape *shape);

#endif
```

**shape.c**
```c
#include "shape.h"

float shape_area(Shape *shape) {
    return shape->vtable->area(shape);
}

void shape_draw(Shape *shape) {
    shape->vtable->draw(shape);
}
```

**circle.h**
```c
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

typedef struct {
    Shape base;
    float radius;
} Circle;

Circle *circle_create(float radius);

#endif
```

**circle.c**
```c
#include "circle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static float circle_area(Shape *shape) {
  Circle *circle = (Circle *)shape;
  return M_PI * circle->radius * circle->radius;
}

static void circle_draw(Shape *shape) {
  Circle *circle = (Circle *)shape;
  printf("Drawing Circle with radius: %.2f\n", circle->radius);
}

// Define the vtable for Circle.
static ShapeVTable circle_vtable = {
  .area = circle_area,
  .draw = circle_draw,
};

Circle *circle_create(float radius) {
  Circle *circle = malloc(sizeof(Circle));
  circle->base.vtable = &circle_vtable;
  circle->radius = radius;

  return circle;
}

void circle_destroy(Circle *circle) {
  free(circle);
}
```

**rectangle.h**
```c
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

typedef struct {
    Shape base;
    float width;
    float height;
} Rectangle;

Rectangle *rectangle_create(float width, float height);

#endif
```

**rectangle.c**
```c
#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

static float rectangle_area(Shape *shape) {
  Rectangle *rect = (Rectangle *)shape;
  return rect->width * rect->height;
}

static void rectangle_draw(Shape *shape) {
  Rectangle *rect = (Rectangle *)shape;
  printf("Drawing Rectangle with width: %.2f and height: %.2f\n", rect->width, rect->height);
}

// Define the vtable for Rectangle
static ShapeVTable rectangle_vtable = {
    .area = rectangle_area,
    .draw = rectangle_draw,
};

Rectangle *rectangle_create(float width, float height) {
  Rectangle *rect = malloc(sizeof(Rectangle));
  rect->base.vtable = &rectangle_vtable;
  rect->width = width;
  rect->height = height;

  return rect;
}

void rectangle_destroy(Rectangle *rect) {
  free(rect);
}
```

**usage:**
```c
#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Shape *rectangle = (Shape *)rectangle_create(4.0f, 3.0f);
  Shape *circle = (Shape *)circle_create(5.0f);

  printf("Rectangle area: %.2f\n", shape_area(rectangle));
  shape_draw(rectangle);

  printf("Circle area: %.2f\n", shape_area(circle));
  shape_draw(circle);

  free(rectangle);
  free(circle);

  return 0;
}
```

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
