#include "shape_factory.h"

#include "geometry_utils.h"
#include "console_io.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

std::unique_ptr<Shape> CircleFactory::creat() {
    std::string name = ConsoleIO::readString("Enter circle name: ");
    Point center = ConsoleIO::readPoint("Center");
    double radius = ConsoleIO::readDouble("Radius: ");
    return std::make_unique<Circle>(name, center, radius);
}

std::unique_ptr<Shape> RectangleFactory::creat() {
    std::string name = ConsoleIO::readString("Enter rectangle name:");
    Point leftTop = ConsoleIO::readPoint("Top-left corner:");
    Point rightBottom = ConsoleIO::readPoint("Bottom-right corner:");
    return std::make_unique<Rectangle>(name, leftTop, rightBottom);
}

std::unique_ptr<Shape> TriangleFactory::creat() {
    std::string name = ConsoleIO::readString("Enter triangle name: ");
    Point p1 = ConsoleIO::readPoint("Point 1");
    Point p2 = ConsoleIO::readPoint("Point 2");
    Point p3 = ConsoleIO::readPoint("Point 3");
    return std::make_unique<Triangle>(name, p1, p2, p3);
}
