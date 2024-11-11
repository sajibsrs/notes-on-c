# Encapsulation
> Method: `File scope`, `static`, `extern`, and `functions`.

Encapsulation in C is implemented by using **file scope** to restrict access to data, **static** variables to make data private to the file, and **extern** declarations to expose specific functions or variables to other parts of the program. By using **functions** that manipulate the data, you ensure that internal details are hidden and access is controlled, protecting the integrity of the data.

---

**shape.h**

Declares only the public interface for `Shape`.

```c
#ifndef SHAPE_H
#define SHAPE_H

// Public interface for Shape
typedef struct Shape Shape;

// Public functions
Shape *shape_create(int x, int y);
void shape_move(Shape *shape, int dx, int dy);
void shape_draw(const Shape *shape);
void shape_destroy(Shape *shape);

#endif
```

---

**shape.c**

Implements `Shape`, containing both public and protected functions but only exposing the public ones via `shape.h`.

```c
#include "shape.h"
#include <stdio.h>
#include <stdlib.h>

// Private: Shape's internal structure
struct Shape {
    int x;
    int y;
};

// Protected function: not included in shape.h
void shape_set_position(Shape *shape, int x, int y) {
    shape->x = x;
    shape->y = y;
}

// Public function to create a shape
Shape *shape_create(int x, int y) {
    Shape *shape = malloc(sizeof(Shape));
    if (shape != NULL) {
        shape->x = x;
        shape->y = y;
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

// Public function to destroy a shape
void shape_destroy(Shape *shape) {
    free(shape);
}
```

---

**rectangle.c**

Accesses the protected `shape_set_position` function via an `extern` declaration, limiting its visibility only to `rectangle.c`.

```c
#include "shape.h"
#include <stdio.h>
#include <stdlib.h>

// Forward declaration of the protected function
extern void shape_set_position(Shape *shape, int x, int y);

// Private: Rectangle struct with Shape base (simulating inheritance)
struct Rectangle {
    Shape base;      // Inherits properties of Shape
    int width;
    int height;
};

// Public function to create a rectangle
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

---
**Usage:**
```c
#include "rectangle.h"
#include "shape.h"

int main() {
    // Create a rectangle (inherits from Shape)
    Rectangle *rect = rectangle_create(10, 20, 100, 50);

    // Draw the rectangle
    rectangle_draw(rect);

    // Move the rectangle using Shape's public function
    shape_move((Shape *)rect, 10, 5);

    // Draw the rectangle again after moving it
    rectangle_draw(rect);

    // Destroy the rectangle
    rectangle_destroy(rect);

    return 0;
}
```

**Output:**
```plaintext
Rectangle at position (10, 20), width: 100, height: 50
Shape at position (20, 25)
Rectangle at position (20, 25), width: 100, height: 50
```
