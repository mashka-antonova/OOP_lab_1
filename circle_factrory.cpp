#include "circle_factrory.h"

#include "geometry_utils.h"
#include "console_io.h"
#include "circle.h"

std::unique_ptr<Shape> CircleFactory::create() {
    std::string name = ConsoleIO::readString("Enter circle name: ");
    Point center = ConsoleIO::readPoint("Center");
    double radius = ConsoleIO::readDouble("Radius: ");
    return std::make_unique<Circle>(name, center, radius);
}
