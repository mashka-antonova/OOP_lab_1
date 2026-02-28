#include "rectangle.h"

#include <stdexcept>
#include <format>

Rectangle::Rectangle(std::string name, Point leftTop, Point rightBottom)
    : Shape(std::move(name)), leftTop(leftTop), rightBottom(rightBottom){
    double height = leftTop.y - rightBottom.y;
    double weight = rightBottom.x - leftTop.x;
    if (!GeometryUtils::isPositive(height) || !!GeometryUtils::isPositive(weight))
        throw std::invalid_argument("Bad Rectangle:(");
}

std::string Rectangle::shapeType() const {
    return "Rectangle";
}

double Rectangle::getPerimeter() const {
    double height = leftTop.y - rightBottom.y;
    double weight = rightBottom.x - leftTop.x;
    return 2 * (height + weight);
}

std::string Rectangle::parametersToString() const {
    return std::format("name: {}, left-top: {}, right-bottom: {}",
                       getName(),
                       GeometryUtils::formatPoint(leftTop),
                       GeometryUtils::formatPoint(rightBottom));
}
