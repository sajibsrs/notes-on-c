#include "circle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static float circle_area(Shape *shape) {
  Circle *circle = (Circle *)shape;
  return M_PI * circle->radius * circle->radius;
}

static void circle_draw(Shape *shape) {
  Circle *circle = (Circle *)shape;
  printf("Drawing Circle with radius: %.2f\n", circle->radius);
}

static ShapeVTable circle_vtable = {
  .area = circle_area,
  .draw = circle_draw,
};

Circle *circle_create(float radius) {
  Circle *circle = malloc(sizeof(Circle));
  circle->base.vtable = &circle_vtable;
  circle->radius = radius;

  return circle;
}

void circle_destroy(Circle *circle) {
  free(circle);
}
