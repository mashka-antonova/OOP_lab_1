#include "shapes_manager.h"

#include "constants.h"

#include <sstream>
#include <iomanip>
#include <algorithm>

void ShapeManager::addShape(std::unique_ptr<Shape> shape){
    shapes.push_back(std::move(shape));
}

std::vector<std::string> ShapeManager::buildParameterLines() const {
    std::vector<std::string> lines;
    for (size_t index = 0; index < shapes.size(); index++) {
        lines.push_back(std::to_string(index + 1) + ". [" + shapes[index]->typeName() + "] " + shapes[index]->parametersToString());
    }
    return lines;
}

std::vector<std::string> ShapeManager::buildPerimeterLines() const {
    std::vector<std::string> lines;
    for (size_t index = 0; index < shapes.size(); index++) {
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(Precision);
        stream << (index + 1) << ". [" << shapes[index]->typeName() << "] name: '" << shapes[index]->getName()
               << "', perimeter: " << shapes[index]->getPerimeter();
        lines.push_back(stream.str());
    }
    return lines;
}

double ShapeManager::calclateTotalPerimeter() const {
    double totalPerimeter = 0.0;
    for (const std::unique_ptr<Shape>& shape : shapes) //
        totalPerimeter += shape->getPerimeter();
    return totalPerimeter;
}

bool compareByPerimeter(const std::unique_ptr<Shape>& left, const std::unique_ptr<Shape>& right) {
    return left->getPerimeter() < right->getPerimeter();
}

void ShapeManager::sortByPerimeterAscending() {
    std::sort(shapes.begin(), shapes.end(), compareByPerimeter);
}

bool ShapeManager::removeByIndex(int oneBasedIndex){
    bool isRemoved = false;
    int index = oneBasedIndex - 1;
    if (index >= 0 && index < static_cast<int>(shapes.size())){
        shapes.erase(shapes.begin() + index);
        isRemoved = true;
    }
    return isRemoved;
}

int ShapeManager::removeWithPerimeterGreaterThan(double threshold) {
    const int oldSize = static_cast<int>(shapes.size());
    shapes.erase(std::remove_if(shapes.begin(), shapes.end(), [threshold](const std::unique_ptr<Shape>& shape) {//
                       return shape->getPerimeter() > threshold;
                   }), shapes.end());
    return oldSize - static_cast<int>(shapes.size());
}

bool ShapeManager::isEmpty() const {
    return shapes.empty();
}
