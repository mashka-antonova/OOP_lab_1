#ifndef CIRCLE_H
#define CIRCLE_H

#include <shape.h>
#include <geometry_utils.h>

class Circle final: public Shape {
public:
    Circle(std::string name, Point center, double radius);
    std::string shapeType() const override;
    double getPerimeter() const override;
    std::string parametersToString() const override;

private:
    Point center;
    double radius;
};

#endif // CIRCLE_H
