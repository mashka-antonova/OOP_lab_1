#ifndef SHAPE_MANAGER_H
#define SHAPE_MANAGER_H

#include <memory>
#include <vector>
#include "shape.h"

class ShapeManager {
public:
    void addShape(std::unique_ptr<Shape> shape);
    std::vector<std::string> buildPerameterList() const;
    std::vector<std::string> buildPerimeterList() const;
    double calculateTotalPerimeter() const;
    void sortByPerimeter();
    bool removeByIndex(int oneBasedIndex);
    int removeByPerimeterGreaterThan(double border);
    bool isEmpty();

private:
    std::vector<std::unique_ptr<Shape>> shapes;
};

#endif // SHAPE_MANAGER_H
