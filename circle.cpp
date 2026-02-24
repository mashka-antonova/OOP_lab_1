#include "circle.h"
#include "shapes.h"

Circle::Circle(std::string name, Point center, double radius) :
    Shape(std::move(name)), center(center), radius(radius){
    if (!isPositive(radius))
        throw std::invalid_argument("Radius must be greater than zero!");
}

std::string Circle::typeName() const {
    return "Circle";
}

double Circle::getPerimeter() const {
    return Two * Pi * radius;
}

std::string Circle:: parametersToString() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(Precision)
           << "name: " << getName() << " center: (" << center.x << ", " << center.y << ") radius: " << radius;
    return stream.str();
}
