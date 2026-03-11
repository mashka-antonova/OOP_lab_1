#include "rectangle_factory.h"

#include "geometry_utils.h"
#include "console_io.h"
#include "rectangle.h"

std::unique_ptr<Shape> RectangleFactory::create() {
    std::string name = ConsoleIO::readString("Enter rectangle name:");
    Point leftTop = ConsoleIO::readPoint("Top-left corner:");
    Point rightBottom = ConsoleIO::readPoint("Bottom-right corner:");
    return std::make_unique<Rectangle>(name, leftTop, rightBottom);
}
