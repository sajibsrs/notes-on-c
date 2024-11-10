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
