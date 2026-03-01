#ifndef SHAPE_CREATOR_H
#define SHAPE_CREATOR_H

#include "shape.h"
#include "shape_type.h"
#include "console_io.h"
#include <functional>
#include <memory>
#include <map>

class ShapeCreator {
public:
    using Creator = std::function<std::unique_ptr<Shape>(ConsoleIO&)>;
    explicit ShapeCreator(ConsoleIO& io);

    std::unique_ptr<Shape> creatShape(ShapeType type) const;

private:
    ConsoleIO& io;
    std::map<ShapeType, Creator> creators;
    void initCreators();
};

#endif // SHAPE_CREATOR_H
