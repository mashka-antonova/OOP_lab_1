#include "shape.h"
#include "geometry_utils.h"

#include <stdexcept>

Shape::Shape(std::string name) : name(std::move(name)) {
    if (GeometryUtils::isBlank(this->name))
        throw std::invalid_argument("Shape's name can't be empty");
}

const std::string& Shape::getName() const{
    return name;
}
