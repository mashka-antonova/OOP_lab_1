#include "triangle.h"
#include "shapes.h"

Triangle::Triangle(std::string name, Point first, Point second, Point third) :
    Shape(std::move(name)), first(first), second(second), third(third){
    const double doubledArea = std::abs(orientation(first, second, third));
    if (!isPositive(doubledArea))
        throw std::invalid_argument("Triangle is degenerate: vertices are collinear");
}

std::string Triangle::typeName() const {
    return "Triangle";
}


double Triangle::getPerimeter() const { //
    const double sideA = distanceBetweenPoints(first, second);
    const double sideB = distanceBetweenPoints(second, third);
    const double sideC = distanceBetweenPoints(third, first);
    return sideA + sideB + sideC;
}

std::string Triangle::parametersToString() const {
    return "name: " + getName() + " , A: (" + formatPoint(first) + "), B: (" + formatPoint(second) + "), C: (" + formatPoint(third) + ")";
}
