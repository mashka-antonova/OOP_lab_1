#include "geometry_utils.h"
#include <cctype>
#include <cmath>
#include <iomanip>
#include <sstream>

bool GeometryUtils::isBlank(const std::string& value) {
    if (value.empty()) return true;
    for (char symbol : value)
        if (!std::isspace(static_cast<unsigned char>(symbol)))
            return false;
    return true;
}

double GeometryUtils::distanceBetweenPoints(const Point& first, const Point& second) {
    const double deltaX = first.x - second.x;
    const double deltaY = first.y - second.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

double GeometryUtils::orientation(const Point& first, const Point& second, const Point& third) {
    const double vectorAx = second.x - first.x;
    const double vectorAy = second.y - first.y;
    const double vectorBx = third.x - first.x;
    const double vectorBy = third.y - first.y;
    return vectorAx * vectorBy - vectorAy * vectorBx;
}

bool GeometryUtils::isPositive(double value) {
    return value > Epsilon;
}

std::string GeometryUtils::formatPoint(const Point& point) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(Precision) << point.x << ", " << point.y;
    return stream.str();
}
