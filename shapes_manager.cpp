#include "shapes_manager.h"

#include "constants.h"

#include <sstream>
#include <iomanip>
#include <algorithm>


void ShapeManager::addShape(ShapePtr shape){
    m_shapes.push_back(std::move(shape));
}

std::vector<std::string> ShapeManager::buildParameterLines() const {
    std::vector<std::string> lines;
    for (size_t index = 0; index < m_shapes.size(); index++) {
        lines.push_back(std::to_string(index + 1) + ". [" + m_shapes[index]->typeName() + "] " + m_shapes[index]->parametersToString());
    }
    return lines;
}

std::vector<std::string> ShapeManager::buildPerimeterLines() const {
    std::vector<std::string> lines;
    for (size_t index = 0; index < m_shapes.size(); index++) {
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(Precision);
        stream << (index + 1) << ". [" << m_shapes[index]->typeName() << "] name: '" << m_shapes[index]->name()
               << "', perimeter: " << m_shapes[index]->perimeter();
        lines.push_back(stream.str());
    }
    return lines;
}

double ShapeManager::calclateTotalPerimeter() const {
    double totalPerimeter = 0.0;
    for (const ShapePtr& shape : m_shapes)
        totalPerimeter += shape->perimeter();
    return totalPerimeter;
}

bool compareByPerimeter(const ShapePtr& left, const ShapePtr& right) {
    return left->perimeter() < right->perimeter();
}

void ShapeManager::sortByPerimeterAscending() {
    std::sort(m_shapes.begin(), m_shapes.end(), compareByPerimeter);
}

bool ShapeManager::removeByIndex(int oneBasedIndex){
    bool IsRemoved = false;
    int index = oneBasedIndex - 1;
    if (index >= 0 && index < static_cast<int>(m_shapes.size())){
        m_shapes.erase(m_shapes.begin() + index);
        IsRemoved = true;
    }
    return IsRemoved;
}

int ShapeManager::removeWithPerimeterGreaterThan(double threshold) {
    const int oldSize = static_cast<int>(m_shapes.size());
    m_shapes.erase(std::remove_if(m_shapes.begin(), m_shapes.end(), [threshold](const ShapePtr& shape) {
                       return shape->perimeter() > threshold;
                   }), m_shapes.end());
    return oldSize - static_cast<int>(m_shapes.size());
}

bool ShapeManager::isEmpty() const {
    return m_shapes.empty();
}
