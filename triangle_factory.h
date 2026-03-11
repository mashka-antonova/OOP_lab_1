#ifndef TRIANGLE_FACTORY_H
#define TRIANGLE_FACTORY_H

#include "shape_factory.h"

class TriangleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> create() override;
};

#endif // TRIANGLE_FACTORY_H
