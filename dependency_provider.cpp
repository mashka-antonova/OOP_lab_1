#include "dependency_provider.h"
#include "circle.h"
#include "circle_factory.h"
#include "rectangle.h"
#include "rectangle_factory.h"
#include "triangle.h"
#include "triangle_factory.h"
#include "polygon.h"
#include "polygon_factory.h"

DependencyProvider::DependencyProvider() {
    initFactories();
}

void DependencyProvider::initFactories() {
    factories[std::type_index(typeid(Circle))] = std::make_unique<CircleFactory>();
    factories[std::type_index(typeid(Rectangle))] = std::make_unique<RectangleFactory>();
    factories[std::type_index(typeid(Triangle))] = std::make_unique<TriangleFactory>();
    factories[std::type_index(typeid(Polygon))] = std::make_unique<PolygonFactory>();
}

Application DependencyProvider::createApplication() {
    ShapeManager manager = createShapeManager();
    ShapeCreator creator = createShapeCreator();
    return Application(std::move(manager), std::move(creator));
}

ShapeManager DependencyProvider::createShapeManager() {
    return ShapeManager();
}

ShapeCreator DependencyProvider::createShapeCreator() {
    std::map<std::type_index, ShapeFactory*> ptrMap;
    for (auto& [type, factory] : factories)
        ptrMap[type] = factory.get();
    return ShapeCreator(std::move(ptrMap));
}

void DependencyProvider::clean() {
    factories.clear();
}
