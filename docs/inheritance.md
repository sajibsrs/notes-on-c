# Inheritance
> Method: Composition and containment.

Inheritance can be achieved by embedding one structure within another, allowing the "child" struct to contain data and functionality from the "parent" struct.

---

**shape.h**

Defines the base Shape structure and an initialization function. This serves as the "parent" structure for other shapes.

```c
#ifndef SHAPE_H
#define SHAPE_H

// Base structure for a shape, containing common properties
typedef struct {
  float x, y;  // Position of the shape
} Shape;

// Initializes a Shape's position
void shape_init(Shape *shape, float x, float y);

#endif
```
---

**shape.c**

Implements the function to initialize a Shape with given coordinates.

```c
#include "shape.h"

// Set the position of the shape
void shape_init(Shape *shape, float x, float y) {
  shape->x = x;
  shape->y = y;
}
```

---

**circle.h**

Defines a Circle structure that includes a Shape as a base and adds a radius field.

```c
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// Circle structure, inheriting from Shape
typedef struct {
  Shape shape;  // Embedded Shape structure (base class)
  float radius; // Circle-specific attribute
} Circle;

// Initializes a Circle's position and radius
void circle_init(Circle *circle, float x, float y, float radius);

// Prints details of the Circle
void circle_print(const Circle *circle);

#endif
```

---

**circle.c**

Implements the circle-specific functions, including initialization and a print function.

```c
#include "circle.h"
#include <stdio.h>

// Initialize the Circle with position and radius, using shape_init for the base
void circle_init(Circle *circle, float x, float y, float radius) {
  shape_init(&circle->shape, x, y);  // Initialize the base Shape part
  circle->radius = radius;
}

// Print details of the Circle, including base position and radius
void circle_print(const Circle *circle) {
  printf("Circle at (%.2f, %.2f) with radius %.2f\n", circle->shape.x, circle->shape.y, circle->radius);
}
```

---

**rectangle.h**

Defines a Rectangle structure that includes a Shape base and adds width and height.

```c
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

// Rectangle structure inheriting Shape by composition
typedef struct {
  Shape shape;       // Embedded Shape struct (base)
  float width, height;  // Rectangle-specific attributes
} Rectangle;

void rectangle_init(Rectangle *rectangle, float x, float y, float width, float height);  // Initialize Rectangle
void rectangle_print(const Rectangle *rectangle);                                       // Print Rectangle details

#endif
```

---

**rectangle.c**

Implements the initialization and printing functions for Rectangle, using the inherited data from Shape.

```c
#include "rectangle.h"
#include <stdio.h>

// Initializes Rectangle, calling shape_init for base struct
void rectangle_init(Rectangle *rectangle, float x, float y, float width, float height) {
  shape_init(&rectangle->shape, x, y);  // Initialize base Shape
  rectangle->width = width;             // Set width
  rectangle->height = height;           // Set height
}

// Prints details of the Rectangle
void rectangle_print(const Rectangle *rectangle) {
  printf("Rectangle at (%.2f, %.2f) with width %.2f and height %.2f\n",
         rectangle->shape.x, rectangle->shape.y, rectangle->width, rectangle->height);
}
```

---

**Usage:**

```c
#include "circle.h"
#include "rectangle.h"

int main(void) {
  Circle circle;
  circle_init(&circle, 2.0f, 3.0f, 5.0f);  // Create and initialize Circle
  circle_print(&circle);                   // Print Circle details

  Rectangle rectangle;
  rectangle_init(&rectangle, 4.0f, 5.0f, 6.0f, 7.0f);  // Create and initialize Rectangle
  rectangle_print(&rectangle);                         // Print Rectangle details

  return 0;
}

```

**Output:**

```plaintext
Circle at (2.00, 3.00) with radius 5.00
Rectangle at (4.00, 5.00) with width 6.00 and height 7.00
```
