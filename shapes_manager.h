#ifndef SHAPES_MANAGER_H
#define SHAPES_MANAGER_H

#include "shapes.h"

class ShapeManager{
public:
    void addShape(ShapePtr shape);
    std::vector<std::string> buildParameterLines() const;
    std::vector<std::string> buildPerimeterLines() const;
    double calclateTotalPerimeter() const;
    void sortByPerimeterAscending();
    bool removeByIndex(int oneBasedIndex);
    int removeWithPerimeterGreaterThan(double border);
    bool isEmpty() const;
private:
    ShapeCollection shapes;
};

#endif // SHAPES_MANAGER_H
