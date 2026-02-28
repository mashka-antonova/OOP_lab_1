#include "triangle.h"

#include <stdexcept>
#include <format>

Triangle::Triangle(std::string name, Point first, Point second, Point third) :
    Shape(std::move(name)), first(first), second(second), third(third) {
    double doubledArea = std::abs(GeometryUtils::orientation(first, second, third));
    if (!GeometryUtils::isPositive(doubledArea))
        throw std::invalid_argument("Triangle is degenerate: vertices are collinear");
}

std::string Triangle::shapeType() const {
    return "Triangle";
}

double Triangle::getPerimeter() const {
    double a = GeometryUtils::distanceBetweenPoints(first, second);
    double b = GeometryUtils::distanceBetweenPoints(first, third);
    double c = GeometryUtils::distanceBetweenPoints(second, third);
    return (a + b + c);
}

std::string Triangle::parametersToString() const {
    return std::format("name: {}, point A: {}, point B: {}, point C: {}",
                       getName(),
                       GeometryUtils::formatPoint(first),
                       GeometryUtils::formatPoint(second),
                       GeometryUtils::formatPoint(third));
}
