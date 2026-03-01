#include "shape_creator.h"

#include "geometry_utils.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

ShapeCreator::ShapeCreator(ConsoleIO& io) : io(io){
    initCreators();
}

void ShapeCreator::initCreators() {
    creators[ShapeType::Circle] = [](ConsoleIO& io) {
        std::string name = io.readString("Enter circle name: ");
        Point center = io.readPoint("Center");
        double radius = io.readDouble("Radius: ");
        return std::make_unique<Circle>(name, center, radius);
    };

    creators[ShapeType::Rectangle] = [](ConsoleIO& io) {
        std::string name = io.readString("Enter rectangle name: ");
        Point leftTop = io.readPoint("Top-left corner");
        Point rightBottom = io.readPoint("Bottom-right corner");
        return std::make_unique<Rectangle>(name, leftTop, rightBottom);
    };

    creators[ShapeType::Triangle] = [](ConsoleIO& io) {
        std::string name = io.readString("Enter triangle name: ");
        Point first = io.readPoint("Point 1");
        Point second = io.readPoint("Point 2");
        Point third = io.readPoint("Point 3");
        return std::make_unique<Triangle>(name, first, second, third);
    };
}

std::unique_ptr<Shape> ShapeCreator::creatShape(ShapeType type) const {
    std::unique_ptr<Shape> shape = nullptr;
    auto it = creators.find(type);
    if (it != creators.end())
        shape = it->second(io);
    return shape;
}
