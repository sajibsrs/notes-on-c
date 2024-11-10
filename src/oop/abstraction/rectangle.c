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
