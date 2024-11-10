#include "circle.h"
#include <stdio.h>

void circle_init(Circle *circle, float x, float y, float radius) {
  shape_init(&circle->shape, x, y);
  circle->radius = radius;
}

void circle_print(const Circle *circle) {
  printf("Circle at (%.2f, %.2f) with radius %.2f\n", circle->shape.x, circle->shape.y, circle->radius);
}
