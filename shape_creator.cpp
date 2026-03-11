#include "shape_creator.h"
#include <stdexcept>

ShapeCreator::ShapeCreator(std::map<std::type_index, ShapeFactory*> factories)
    : factories(std::move(factories)) {}

std::unique_ptr<Shape> ShapeCreator::createShape(std::type_index type) {
    auto it = factories.find(type);
    if (it == factories.end())
        throw std::invalid_argument("unknown shape type");
    return it->second->create();
}
