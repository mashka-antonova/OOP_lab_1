#ifndef APPLICATION_H
#define APPLICATION_H

#include "console_io.h"
#include "shapes_manager.h"
#include <map>
#include <functional>

class Application{
public:
    explicit Application(ConsoleIo& console);
    int run();

private:
    int handleMenuAction(int action);
    void initHandlers();
    void printMenu();
    void printShapeChoice();
    std::unique_ptr<Shape> createShape();
    void addShape();
    void sortByPerimeters();
    void exit();
    void printParameterList();
    void printPerimeterList();
    void printTotalPerimeter();
    void deleteShapeByIndex();
    void deleteShapeByPerimeter();

    std::map<int, std::function<void()>> handlers;

    ConsoleIo& console;
    ShapeManager shapeManager;
};


#endif // APPLICATION_H
