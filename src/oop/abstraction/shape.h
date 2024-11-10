#ifndef SHAPE_H
#define SHAPE_H

typedef struct Shape Shape;
typedef struct ShapeVTable ShapeVTable; // Shape virtual table.

struct ShapeVTable {
  float (*area)(Shape *self);
  void (*draw)(Shape *self);
};

struct Shape {
  ShapeVTable *vtable;
};

float shape_area(Shape *shape);
void shape_draw(Shape *shape);

#endif
