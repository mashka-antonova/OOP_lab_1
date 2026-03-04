#include "polygon.h"

#include "polygon.h"

#include <cmath>
#include <format>
#include <stdexcept>

Polygon::Polygon(std::string name, std::vector<Point> inputPeaks)
    : Shape(std::move(name)), peaks(std::move(inputPeaks)) {
    if (this->peaks.size() < 3)
        throw std::invalid_argument("polygon must have at least 3 vertices");

    for (size_t i = 0; i < peaks.size(); ++i) {
        size_t next = (i + 1) % peaks.size();
        if (GeometryUtils::pointsAreEqual(peaks[i], peaks[next]))
            throw std::invalid_argument("polygon has repeating adjacent vertices");
    }

    double expectedSign = 0.0;
    for (size_t i = 0; i < peaks.size(); ++i) {
        const Point& first = peaks[i];
        const Point& second = peaks[(i + 1) % peaks.size()];
        const Point& third = peaks[(i + 2) % peaks.size()];

        double turn = GeometryUtils::orientation(first, second, third);
        if (std::abs(turn) <= EPS)
            throw std::invalid_argument("polygon is degenerate: adjacent edges are collinear");

        if (expectedSign == 0.0)
            expectedSign = turn;
        else if (turn * expectedSign < 0.0)
            throw std::invalid_argument("polygon must be convex and peaks must be in boundary order");
    }
}

std::string Polygon::shapeType() const {
    return "Polygon";
}

double Polygon::getPerimeter() const {
    double perimeter = 0.0;
    for (size_t i = 0; i < peaks.size(); ++i) {
        perimeter += GeometryUtils::distanceBetweenPoints(peaks[i], peaks[(i + 1) % peaks.size()]);
    }
    return perimeter;
}

std::string Polygon::parametersToString() const {
    std::string peaksDescription;
    for (size_t i = 0; i < peaks.size(); ++i)
        peaksDescription += std::format("{}{}", i == 0 ? "" : ", ", GeometryUtils::formatPoint(peaks[i]));

    return std::format("name: {}, vertices count: {}, peaks: [{}]",
                       getName(),
                       peaks.size(),
                       peaksDescription);
}
