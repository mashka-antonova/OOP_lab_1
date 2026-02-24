#include "triangle.h"
#include "shapes.h"
#include <stdexcept>

Triangle::Triangle(std::string name, Point first, Point second, Point third) :
    Shape(std::move(name)), first(first), second(second), third(third){
    const double doubledArea = std::abs(GeometryUtils::orientation(first, second, third));
    if (!GeometryUtils::isPositive(doubledArea))
        throw std::invalid_argument("Triangle is degenerate: vertices are collinear");
}

std::string Triangle::typeName() const {
    return "Triangle";
}


double Triangle::getPerimeter() const {
    const double sideA = GeometryUtils::distanceBetweenPoints(first, second);
    const double sideB = GeometryUtils::distanceBetweenPoints(second, third);
    const double sideC = GeometryUtils::distanceBetweenPoints(third, first);
    return sideA + sideB + sideC;
}

std::string Triangle::parametersToString() const {
    return "name: " + getName() + " , A: (" + GeometryUtils::formatPoint(first) + "), B: (" + GeometryUtils::formatPoint(second) + "), C: (" + GeometryUtils::formatPoint(third) + ")";
}
