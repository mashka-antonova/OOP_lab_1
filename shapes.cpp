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
Shape::Shape(std::string name) : name(name) {
    if (isBlank(name))
        throw std::invalid_argument("Shape's name can't be empty");
}

const std::string& Shape:: getName() const {
    return name;
}



