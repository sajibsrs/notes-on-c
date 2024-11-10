#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

typedef struct {
    Shape base;
    float radius;
} Circle;

Circle *circle_create(float radius);

#endif
