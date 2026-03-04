#ifndef SHAPE_CREATOR_H
#define SHAPE_CREATOR_H

#include <memory>
#include <map>
#include <functional>
#include "shape.h"
#include "shape_type.h"
#include "console_io.h"

class ShapeCreator {
public:
    using Creator = std::function<std::unique_ptr<Shape>(ConsoleIO&)>;

    explicit ShapeCreator(ConsoleIO& io); //
    std::unique_ptr<Shape> creatShape(ShapeType type) const;

private:
    ConsoleIO& io;
    std::map<ShapeType, Creator> creators;

    void initCreators();

    static std::unique_ptr<Shape> createCircle(ConsoleIO& io);
    static std::unique_ptr<Shape> createRectangle(ConsoleIO& io);
    static std::unique_ptr<Shape> createTriangle(ConsoleIO& io);
};

#endif
