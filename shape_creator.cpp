#include "shape_creator.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

ShapeCreator::ShapeCreator(ConsoleIO& io) : io(io) {
    initCreators();
}

void ShapeCreator::initCreators() {
    creators[ShapeType::Circle] = createCircle;
    creators[ShapeType::Rectangle] = createRectangle;
    creators[ShapeType::Triangle] = createTriangle;
}

std::unique_ptr<Shape> ShapeCreator::creatShape(ShapeType type) const {
    std::unique_ptr<Shape> shape = nullptr;
    auto it = creators.find(type);
    if (it != creators.end())
        shape = it->second(io);
    return shape;
}

std::unique_ptr<Shape> ShapeCreator::createCircle(ConsoleIO& io) {
    std::string name = io.readString("Enter circle name: ");
    Point center = io.readPoint("Center");
    double radius = io.readDouble("Radius: ");
    return std::make_unique<Circle>(name, center, radius);
}

std::unique_ptr<Shape> ShapeCreator::createRectangle(ConsoleIO& io) {
    std::string name = io.readString("Enter rectangle name: ");
    Point leftTop = io.readPoint("Top-left corner");
    Point rightBottom = io.readPoint("Bottom-right corner");
    return std::make_unique<Rectangle>(name, leftTop, rightBottom);
}

std::unique_ptr<Shape> ShapeCreator::createTriangle(ConsoleIO& io) {
    std::string name = io.readString("Enter triangle name: ");
    Point p1 = io.readPoint("Point 1");
    Point p2 = io.readPoint("Point 2");
    Point p3 = io.readPoint("Point 3");
    return std::make_unique<Triangle>(name, p1, p2, p3);
}
