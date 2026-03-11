#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include <memory>
#include <shape.h>

class ShapeFactory {
public:
    virtual ~ShapeFactory() = default;
    virtual std::unique_ptr<Shape> create() = 0;
};

#endif // SHAPE_FACTORY_H
