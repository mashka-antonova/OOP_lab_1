#ifndef TRIANGLE_FACTORY_H
#define TRIANGLE_FACTORY_H

#include "shape_factory.h"

class TriangleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> creat() override;
};

#endif // TRIANGLE_FACTORY_H
