#ifndef GEOMETRY_UTILS_H
#define GEOMETRY_UTILS_H

#define EPS 1e-12

#include <string>

struct Point{
    double x, y;
};

class GeometryUtils{
public:
    GeometryUtils() = delete;

    static bool isBlank(const std::string& value);
    static double distanceBetweenPoints(const Point& a, const Point& b);
    static double orientation(const Point& first, const Point& second, const Point& third);
    static bool isPositive(const double value);
    static std::string formatPoint(const Point& point);
};

#endif // GEOMETRY_UTILS_H
