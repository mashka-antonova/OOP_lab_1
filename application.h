#ifndef APPLICATION_H
#define APPLICATION_H

#include "console_io.h"
#include "shapes_manager.h"


class Application{
public:
    explicit Application(ConsoleIo& console);
    int run();

private:
    int handleMenuAction(int action);
    void printMenu();
    ShapePtr createShape();
    void printParameterList();
    void printPerimeterList();
    void printTotalPerimeter();
    void deleteShapeByIndex();
    void deleteShapeByPerimeter();

    ConsoleIo& console;
    ShapeManager shapeManager;
};


#endif // APPLICATION_H
