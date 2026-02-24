#include "rectangle.h"
#include "shapes.h"
#include <stdexcept>

Rectangle::Rectangle(std::string name, Point leftTop, Point rightBottom) :
    Shape(std::move(name)), leftTop(leftTop), rightBottom(rightBottom){
    const double width = rightBottom.x - leftTop.x;
    const double height = leftTop.y - rightBottom.y;
    if (!GeometryUtils::isPositive(width) || !GeometryUtils::isPositive(height))
        throw std::invalid_argument("The points of the rectangle are invalid");
}

std::string Rectangle::typeName() const{
    return "Rectangle";
}

double Rectangle::getPerimeter() const{
    const double width = rightBottom.x - leftTop.x;
    const double height = leftTop.y - rightBottom.y;
    return Two * (width + height);
}

std::string Rectangle::parametersToString() const {
    return "name: " + getName() + ", left-top: (" + GeometryUtils::formatPoint(leftTop) + "), right-bottom: (" + GeometryUtils::formatPoint(rightBottom) + ")";
}

