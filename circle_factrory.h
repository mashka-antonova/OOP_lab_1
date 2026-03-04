#ifndef CIRCLE_FACTRORY_H
#define CIRCLE_FACTRORY_H

#include "shape_factory.h"

class CircleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> creat() override;
};

#endif // CIRCLE_FACTRORY_H
