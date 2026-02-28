#include "geometry_utils.h"

#include <cmath>
#include <format>

bool GeometryUtils::isBlank(const std::string& value){
    bool isBlank = true;
    for (char c : value){
        if (!std::isspace(static_cast<unsigned char>(c))){
            isBlank = false;
            break;
        }
    }
    return isBlank;
}

double GeometryUtils::distanceBetweenPoints(const Point& a, const Point& b){
    double deltaX = b.x - a.x;
    double deltaY = b.y - a.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

double GeometryUtils::orientation(const Point& first, const Point& second, const Point& third) {
    const double vectorAx = second.x - first.x;
    const double vectorAy = second.y - first.y;
    const double vectorBx = third.x - first.x;
    const double vectorBy = third.y - first.y;
    return vectorAx * vectorBy - vectorAy * vectorBx;
}

bool GeometryUtils::isPositive(double value){
    return value > EPS;
}

std::string GeometryUtils::formatPoint(const Point& point) {
    return std::format("({:.3f}, {:.3f})", point.x, point.y);
}
