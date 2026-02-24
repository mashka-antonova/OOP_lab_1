#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shapes.h"

class Rectangle final: public Shape{
public:
    Rectangle(std::string name, Point leftTop, Point rightBottom);
    std::string typeName() const override;
    double getPerimeter() const override;
    std::string parametersToString() const override;

private:
    Point leftTop;
    Point rightBottom;
};

#endif // RECTANGLE_H
