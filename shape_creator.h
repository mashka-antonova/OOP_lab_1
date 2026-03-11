#ifndef SHAPE_CREATOR_H
#define SHAPE_CREATOR_H

#include <memory>
#include <map>
#include <shape.h>
#include "shape_factory.h"
#include <typeindex>

class ShapeCreator {
public:
    explicit ShapeCreator(std::map<std::type_index, ShapeFactory*> factories);
    std::unique_ptr<Shape> creatShape(std::type_index type);

private:
    std::map<std::type_index, ShapeFactory*> factories;
};

#endif
