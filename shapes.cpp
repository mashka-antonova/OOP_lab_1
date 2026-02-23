#include "shapes.h"

#include "constants.h"

#include <cctype>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stdexcept>

//вспомогательные функции

bool isBlank(const std::string& value) {
    bool isBlank = true;
    for (char symbol : value)
        if (!std::isspace(static_cast<unsigned char>(symbol)))
            isBlank = false;
    return isBlank;
}

double distanceBetweenPoints(const Point& first, const Point& second) {
    const double deltaX = first.x - second.x;
    const double deltaY = first.y - second.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

double orientation(const Point& first, const Point& second, const Point& third) {
    const double vectorAx = second.x - first.x;
    const double vectorAy = second.y - first.y;
    const double vectorBx = third.x - first.x;
    const double vectorBy = third.y - first.y;
    return vectorAx * vectorBy - vectorAy * vectorBx; // > 0 point 3 левее вектора 1->2
}

bool isPositive(double value){
    return value > Epsilon;
}

std::string formatPoint(const Point& point) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(Precision) << point.x << ", " << point.y;
    return stream.str();
}

//реализация методов
Shape::Shape(std::string name) : m_name(std::move(name)){
    if (isBlank(m_name))
        throw std::invalid_argument("Shape's name can't be empty");
}

const std::string& Shape:: name() const {
    return m_name;
}

Circle::Circle(std::string name, Point center, double radius) :
    Shape(std::move(name)), m_center(center), m_radius(radius){
    if (!isPositive(m_radius))
        throw std::invalid_argument("Radius must be greater than zero!");
}

std::string Circle::typeName() const {
    return "Circle";
}

double Circle::perimeter() const {
    return Two * Pi * m_radius;
}

std::string Circle:: parametersToString() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(Precision)
           << "name: " << name() << " center: (" << m_center.x << ", " << m_center.y << ") radius: " << m_radius;
    return stream.str();
}

Rectangle::Rectangle(std::string name, Point leftTop, Point rightBottom) :
    Shape(std::move(name)), m_leftTop(leftTop), m_rightBottom(rightBottom){
    const double width = m_rightBottom.x - m_leftTop.x;
    const double height = m_leftTop.y - m_rightBottom.y;
    if (!isPositive(width) || !isPositive(height))
        throw std::invalid_argument("The points of the rectangle are invalid");
}

std::string Rectangle::typeName() const{
    return "Rectangle";
}

double Rectangle::perimeter() const{
    const double width = m_rightBottom.x - m_leftTop.x;
    const double height = m_leftTop.y - m_rightBottom.y;
    return Two * (width + height);
}

std::string Rectangle::parametersToString() const {
    return "name: " + name() + ", left-top: (" + formatPoint(m_leftTop) + "), right-bottom: (" + formatPoint(m_rightBottom) + ")";
}

Triangle::Triangle(std::string name, Point first, Point second, Point third) :
    Shape(std::move(name)), m_first(first), m_second(second), m_third(third){
    const double doubledArea = std::abs(orientation(m_first, m_second, m_third));
    if (!isPositive(doubledArea))
        throw std::invalid_argument("Triangle is degenerate: vertices are collinear");
}

std::string Triangle::typeName() const {
    return "Triangle";
}


double Triangle::perimeter() const {
    const double sideA = distanceBetweenPoints(m_first, m_second);
    const double sideB = distanceBetweenPoints(m_second, m_third);
    const double sideC = distanceBetweenPoints(m_third, m_first);
    return sideA + sideB + sideC;
}

std::string Triangle::parametersToString() const {
    return "name: " + name() + " , A: (" + formatPoint(m_first) + "), B: (" + formatPoint(m_second) + "), C: (" + formatPoint(m_third) + ")";
}
