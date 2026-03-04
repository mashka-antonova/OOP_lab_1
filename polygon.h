#ifndef POLYGON_H
#define POLYGON_H

#define MIN_COUNT_OF_PEAKS 3

#include "shape.h"
#include "geometry_utils.h"
#include <vector>

class Polygon final : public Shape {
public:
    Polygon(std::string name, std::vector<Point> vertices);

    std::string shapeType() const override;
    double getPerimeter() const override;
    std::string parametersToString() const override;

private:
    std::vector<Point> peaks;
};

#endif // POLYGON_H
