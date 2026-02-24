#ifndef SHAPES_H
#define SHAPES_H

#include "constants.h"

#include <string>
#include <memory>
#include <vector>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stdexcept>

struct Point{
    double x;
    double y;
};

class Shape{
public:
    explicit Shape(std::string name);
    virtual ~Shape() = default;

    const std::string& getName() const;
    virtual std::string typeName() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string parametersToString() const = 0;

private:
    std::string name;
};

using ShapePtr = std::unique_ptr<Shape>;
using ShapeCollection = std::vector<ShapePtr>;

bool isBlank(const std::string& value);
double distanceBetweenPoints(const Point& first, const Point& second);
double orientation(const Point& first, const Point& second, const Point& third);
bool isPositive(double value);
std::string formatPoint(const Point& point);

#endif // SHAPES_H
