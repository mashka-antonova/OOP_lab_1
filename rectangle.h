#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "geometry_utils.h"

class Rectangle final: public Shape {
public:
    Rectangle(std::string name, Point leftTop, Point rightBottom);

    std::string shapeType() const override;
    double getPerimeter() const override;
    std::string parametersToString() const override;

public:
    Point leftTop;
    Point rightBottom;
};

#endif // RECTANGLE_H
