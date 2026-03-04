#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include <memory>
#include <shape.h>

class ShapeFactory {
public:
    virtual ~ShapeFactory() = default;
    virtual std::unique_ptr<Shape> creat() = 0;
};

class CircleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> creat() override;
};

class RectangleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> creat() override;
};

class TriangleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> creat() override;
};

#endif // SHAPE_FACTORY_H
