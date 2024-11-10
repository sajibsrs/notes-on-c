# Encapsulation
> Method: `Structs` with `functions` and `static` variables.

Encapsulation in C can be managed by using opaque pointers, static variables, and functions that operate only on data within a given scope. To hide the inner details of a struct, you can only expose a pointer to it without revealing its full structure.

shape.h

Public interface for Shape. The shape_create and shape_draw functions are accessible to all, while shape_set_position is available as extern, simulating protected access for use in derived types.

```c
#ifndef SHAPE_H
#define SHAPE_H

// Public interface for Shape
typedef struct Shape Shape;

// Public functions
Shape *shape_create(int x, int y);
void shape_move(Shape *shape, int dx, int dy);
void shape_draw(const Shape *shape);

// Protected function (made available through extern)
extern void shape_set_position(Shape *shape, int x, int y);

#endif
```

shape.c

This file includes private data (Shape's internal details) and protected methods that are only accessible to files that declare extern for shape_set_position.

```c
#include "shape.h"
#include <stdio.h>
#include <stdlib.h>

// Private: Shape's internal structure, only accessible within shape.c
struct Shape {
    int x;
    int y;
};

// Public function to create a shape
Shape *shape_create(int x, int y) {
    Shape *shape = malloc(sizeof(Shape));
    if (shape != NULL) {
        shape_set_position(shape, x, y);  // Use protected method to initialize
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

// Protected function: accessible through `extern`
void shape_set_position(Shape *shape, int x, int y) {
    shape->x = x;
    shape->y = y;
}

// Private function: only accessible within this file
static void shape_private_method() {
    // Internal use only
}
```

rectangle.h

This header defines a derived type, Rectangle, which uses Shape as its base and can access shape_set_position due to its protected designation.

```c
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

// Public interface for Rectangle
typedef struct Rectangle Rectangle;

// Public functions
Rectangle *rectangle_create(int x, int y, int width, int height);
void rectangle_draw(const Rectangle *rect);
void rectangle_destroy(Rectangle *rect);

#endif
```

rectangle.c

Implements Rectangle and uses protected functions from Shape via extern.

```c
#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

// Private: Rectangle struct with Shape base
struct Rectangle {
    Shape base;      // "Protected" inheritance of Shape
    int width;
    int height;
};

// Public function to create rectangle
Rectangle *rectangle_create(int x, int y, int width, int height) {
    Rectangle *rect = malloc(sizeof(Rectangle));
    if (rect != NULL) {
        shape_set_position(&rect->base, x, y);  // Access protected function
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

Main program demonstrating encapsulation in action.

```c
#include "rectangle.h"
#include "shape.h"

int main() {
    // Create a rectangle (inherits from Shape)
    Rectangle *rect = rectangle_create(10, 20, 100, 50);

    // Draw the rectangle
    rectangle_draw(rect);

    // Move the rectangle
    shape_move((Shape *)rect, 10, 5);  // Use Shape's public interface

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
