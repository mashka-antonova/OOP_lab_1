#include "circle.h"
#include <iomanip>
#include <sstream>

Circle::Circle(std::string name, Point center, double radius) :
    Shape(std::move(name)), center(center), radius(radius) {
    if (!GeometryUtils::isPositive(radius)) {
        throw std::invalid_argument("Radius must be greater than zero!");
    }
}

std::string Circle::typeName() const {
    return "Circle";
}

double Circle::getPerimeter() const {
    return Two * Pi * radius;
}

std::string Circle::parametersToString() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(Precision)
           << "name: " << getName()
           << " center: (" << GeometryUtils::formatPoint(center) << ")"
           << " radius: " << radius;
    return stream.str();
}
