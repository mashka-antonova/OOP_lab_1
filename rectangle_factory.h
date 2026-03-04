#ifndef RECTANGLE_FACTORY_H
#define RECTANGLE_FACTORY_H

#include "shape_factory.h"

class RectangleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> creat() override;
};

#endif // RECTANGLE_FACTORY_H
