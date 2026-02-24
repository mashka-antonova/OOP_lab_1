#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shapes.h"

class Triangle final: public Shape{
public:
    Triangle(std::string name, Point first, Point second, Point third);
    std::string typeName() const override;
    double getPerimeter() const override;
    std::string parametersToString() const override;

private:
    Point first;
    Point second;
    Point third;
};

#endif
