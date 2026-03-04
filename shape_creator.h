#ifndef SHAPE_CREATOR_H
#define SHAPE_CREATOR_H

#include <memory>
#include <map>
#include <shape.h>
#include <shape_type.h>
#include "shape_factory.h"

class ShapeCreator {
public:
    ShapeCreator();
    std::unique_ptr<Shape> creatShape(ShapeType type);
private:
    std::map<ShapeType, std::unique_ptr<ShapeFactory>> factories;
    void initFactories();
};

#endif
