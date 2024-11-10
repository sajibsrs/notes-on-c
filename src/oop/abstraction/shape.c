#include "shape.h"

float shape_area(Shape *shape) {
    return shape->vtable->area(shape);
}

void shape_draw(Shape *shape) {
    shape->vtable->draw(shape);
}
