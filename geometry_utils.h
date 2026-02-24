#ifndef GEOMETRY_UTILS_H
#define GEOMETRY_UTILS_H

#include "constants.h"
#include <string>

struct Point {
    double x;
    double y;
};

class GeometryUtils {
public:
    GeometryUtils() = delete;
    static bool isBlank(const std::string& value);
    static double distanceBetweenPoints(const Point& first, const Point& second);
    static double orientation(const Point& first, const Point& second, const Point& third);
    static bool isPositive(double value);
    static std::string formatPoint(const Point& point);
};

#endif // GEOMETRY_UTILS_H
