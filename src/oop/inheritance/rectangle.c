#include "rectangle.h"
#include <stdio.h>

void rectangle_init(Rectangle *rectangle, float x, float y, float width, float height) {
    shape_init(&rectangle->shape, x, y);
    rectangle->width = width;
    rectangle->height = height;
}

void rectangle_print(const Rectangle *rectangle) {
    printf("Rectangle at (%.2f, %.2f) with width %.2f and height %.2f\n", rectangle->shape.x, rectangle->shape.y,
           rectangle->width, rectangle->height);
}
