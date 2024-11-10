# Encapsulation
> Method: `Structs` with `functions` and `static` variables.

Encapsulation in C can be managed by using opaque pointers, static variables, and functions that operate only on data within a given scope. To hide the inner details of a struct, you can only expose a pointer to it without revealing its full structure.

shape.h

Header file (exposing public interface)
```c
#ifndef SHAPE_H
#define SHAPE_H

// Public Interface
typedef struct Shape Shape;

// Public functions
Shape *shape_create(int x, int y);
void shape_move(Shape *shape, int dx, int dy);
void shape_draw(const Shape *shape);
void shape_destroy(Shape *shape);

// Protected functions (made public for subclass)
void shape_set_position(Shape *shape, int x, int y);

#endif
```

shape.c

Base class file (protected and private implementation)
```c
#include "shape.h"
#include <stdio.h>
#include <stdlib.h>

// Private: internal struct definition and static variables
struct Shape {
    int x;
    int y;
};

// Public function to create shape
Shape *shape_create(int x, int y) {
    Shape *shape = malloc(sizeof(Shape));
    if (shape != NULL) {
        shape_set_position(shape, x, y);  // protected
    }
    return shape;
}

// Public function to move shape
void shape_move(Shape *shape, int dx, int dy) {
    shape->x += dx;
    shape->y += dy;
    shape_draw(shape);
}

// Public function to draw shape
void shape_draw(const Shape *shape) {
    printf("Shape at position (%d, %d)\n", shape->x, shape->y);
}

// Private function to set position (only accessible within this file)
static void shape_set_position(Shape *shape, int x, int y) {
    shape->x = x;
    shape->y = y;
}

// Private function to destroy shape (only accessible within this file)
static void shape_destroy(Shape *shape) {
    free(shape);
}
```

rectangle.h

Derived class header (public, protected, and private)
```c
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

// Public Interface for Rectangle (inherits Shape)
typedef struct Rectangle Rectangle;

// Public functions
Rectangle *rectangle_create(int x, int y, int width, int height);
void rectangle_draw(const Rectangle *rect);
void rectangle_destroy(Rectangle *rect);

#endif
```

rectangle.c

Derived class implementation
```c
#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

// Private: internal Rectangle struct, with Shape as base (simulating inheritance)
struct Rectangle {
    Shape base;      // "protected" inheritance
    int width;
    int height;
};

// Public function to create rectangle
Rectangle *rectangle_create(int x, int y, int width, int height) {
    Rectangle *rect = malloc(sizeof(Rectangle));
    if (rect != NULL) {
        shape_set_position(&rect->base, x, y);  // protected access to Shape
        rect->width = width;
        rect->height = height;
    }
    return rect;
}

// Public function to draw rectangle
void rectangle_draw(const Rectangle *rect) {
    printf("Rectangle at position (%d, %d), width: %d, height: %d\n",
            rect->base.x, rect->base.y, rect->width, rect->height);
}

// Public function to destroy rectangle
void rectangle_destroy(Rectangle *rect) {
    free(rect);
}
```

main.c

Main function to demonstrate usage
```c
#include "rectangle.h"
#include "shape.h"

int main() {
    // Create a rectangle (inherits from Shape)
    Rectangle *rect = rectangle_create(10, 20, 100, 50);

    // Draw the rectangle
    rectangle_draw(rect);

    // Move the rectangle
    shape_move((Shape *)rect, 10, 5);  // Using the Shape interface

    // Destroy the rectangle
    rectangle_destroy(rect);

    return 0;
}
```

Output:
```plaintext
Rectangle at position (10, 20), width: 100, height: 50
Shape at position (20, 25)
```
