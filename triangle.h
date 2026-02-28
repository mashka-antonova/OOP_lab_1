#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "geometry_utils.h"

class Triangle final: public Shape {
public:
    Triangle(std::string name, Point first, Point second, Point third);

    std::string shapeType() const override;
    double getPerimeter() const override;
    std::string parametersToString() const override;

private:
    Point first, second, third;
};

#endif // TRIANGLE_H
