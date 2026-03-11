#ifndef DEPENDENCY_PROVIDER_H
#define DEPENDENCY_PROVIDER_H

#include <map>
#include <memory>
#include "shape_factory.h"
#include "application.h"
#include "typeindex"

class DependencyProvider {
public:
    DependencyProvider();
    Application createApplication();
    void clean();
private:
    void initFactories();
    ShapeManager createShapeManager();
    ShapeCreator creatShapeCreator();
    std::map<std::type_index, std::unique_ptr<ShapeFactory>> factories;
};

#endif
