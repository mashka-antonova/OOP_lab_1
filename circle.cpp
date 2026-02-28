#include "circle.h"

#include <stdexcept>
#include <numbers>
#include <format>

Circle::Circle(std::string name, Point center, double radius)
    : Shape(std::move(name)), center(center), radius(radius) {
    if (!GeometryUtils::isPositive(radius))
        throw std::invalid_argument("Radius must be positive!");
}

std::string Circle::shapeType() const {
    return "Circle";
}

double Circle::getPerimeter() const {
    return 2 * radius * std::numbers::pi;
}

std::string Circle::parametersToString() const {
    return std::format(
        "name: {}, center: {}, radius: {:.3f}",
        getName(), GeometryUtils::formatPoint(center), radius);
}
