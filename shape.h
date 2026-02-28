#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    explicit Shape(std::string name);
    virtual ~Shape() = default;

    const std::string& getName() const;

    virtual std::string shapeType() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string parametersToString() const = 0;

private:
    std::string name;
};

#endif // SHAPE_H
