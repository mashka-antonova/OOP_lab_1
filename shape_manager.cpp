#include "shape_manager.h"

#include <format>
#include <memory>
#include <algorithm>

void ShapeManager::addShape(std::unique_ptr<Shape> shape) {
    shapes.push_back(std::move(shape));
}

std::vector<std::string> ShapeManager::buildPerameterList() const {
    std::vector<std::string> lines;
    for (size_t i = 0; i < shapes.size(); i++)
        lines.push_back(std::format("{} {} {}",
                                    i + 1,
                                    shapes[i]->shapeType(),
                                    shapes[i]->parametersToString()));
    return lines;
}

std::vector<std::string> ShapeManager::buildPerimeterList() const {
    std::vector<std::string> lines;
    for (size_t i = 0; i < shapes.size(); i++)
        lines.push_back(std::format("{} {} {} Perimeter: {}",
                                    i + 1,
                                    shapes[i]->getName(),
                                    shapes[i]->shapeType(),
                                    shapes[i]->getPerimeter()));
    return lines;
}

double ShapeManager::calculateTotalPerimeter() const {
    double totalPerimeter = 0.0;
    for (const std::unique_ptr<Shape>& shape : shapes)
        totalPerimeter += shape->getPerimeter();
    return totalPerimeter;
}

bool compareByPerimeter(const std::unique_ptr<Shape>& left, const std::unique_ptr<Shape>& right) {
    return left->getPerimeter() < right->getPerimeter();
}

void ShapeManager::sortByPerimeter() {
    std::sort(shapes.begin(), shapes.end(), compareByPerimeter);
}

bool ShapeManager::removeByIndex(int oneBasedIndex) {
    bool isRemoved = false;
    int index = oneBasedIndex - 1;
    if (index >= 0 && index < static_cast<int>(shapes.size())) {
        shapes.erase(shapes.begin() + index);
        isRemoved = true;
    }
    return isRemoved;
}

int ShapeManager::removeByPerimeterGreaterThan(double border) {
    int removedCount = std::erase_if(shapes, [border](const std::unique_ptr<Shape>& s){
        return s->getPerimeter() > border;
    });
    return removedCount;
}
