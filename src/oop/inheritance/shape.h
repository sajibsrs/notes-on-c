#ifndef SHAPE_H
#define SHAPE_H

typedef struct {
    float x, y;
} Shape;

void shape_init(Shape *shape, float x, float y);

#endif
