#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

typedef struct {
    Shape shape;
    float width, height;
} Rectangle;

void rectangle_init(Rectangle *rectangle, float x, float y, float width, float height);
void rectangle_print(const Rectangle *rectangle);

#endif
