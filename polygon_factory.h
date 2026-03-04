#ifndef POLYGON_FACTORY_H
#define POLYGON_FACTORY_H

#include "shape_factory.h"

class PolygonFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> creat() override;
};

#endif // POLYGON_FACTORY_H
