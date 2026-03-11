#ifndef CIRCLE_FACTORY_H
#define CIRCLE_FACTORY_H

#include "shape_factory.h"

class CircleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> create() override;
};

#endif // CIRCLE_FACTORY_H
