#include "shape_creator.h"

#include <memory>
#include <circle_factrory.h>
#include <rectangle_factory.h>
#include <triangle_factory.h>
#include <polygon_factory.h>

ShapeCreator::ShapeCreator() {
    initFactories();
}

void ShapeCreator::initFactories() {
    factories[ShapeType::Circle] = std::make_unique<CircleFactory>();
    factories[ShapeType::Rectangle] = std::make_unique<RectangleFactory>();
    factories[ShapeType::Triangle] = std::make_unique<TriangleFactory>();
    factories[ShapeType::Polygon] = std::make_unique<PolygonFactory>();
}

std::unique_ptr<Shape> ShapeCreator::creatShape(ShapeType type) {
    auto it = factories.find(type);
    if (it == factories.end())
        throw std::invalid_argument("unknown shape type");
    return it->second->creat();
}
