#ifndef SHAPES_H
#define SHAPES_H

#include "geometry_utils.h"
#include <string>
#include <memory>
#include <vector>

class Shape {
public:
    explicit Shape(std::string name);
    virtual ~Shape() = default;

    const std::string& getName() const;
    virtual std::string typeName() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string parametersToString() const = 0;

private:
    std::string name;
};

using ShapePtr = std::unique_ptr<Shape>;
using ShapeCollection = std::vector<ShapePtr>;

#endif // SHAPES_H
