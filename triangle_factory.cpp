#include "triangle_factory.h"

#include "geometry_utils.h"
#include "console_io.h"
#include "triangle.h"

std::unique_ptr<Shape> TriangleFactory::create() {
    std::string name = ConsoleIO::readString("Enter triangle name: ");
    Point p1 = ConsoleIO::readPoint("Point 1");
    Point p2 = ConsoleIO::readPoint("Point 2");
    Point p3 = ConsoleIO::readPoint("Point 3");
    return std::make_unique<Triangle>(name, p1, p2, p3);
}
