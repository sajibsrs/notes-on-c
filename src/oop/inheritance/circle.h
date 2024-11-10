#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

typedef struct {
  Shape shape;
  float radius;
} Circle;

void circle_init(Circle *circle, float x, float y, float radius);
void circle_print(const Circle *circle);

#endif
