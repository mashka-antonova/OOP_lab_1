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
    ShapePtr creatShape();
    void printParameterList();
    void printPerimeterList();
    void printTotalPerimeter();
    void deleteShapeByIndex();
    void deleteShapeByPerimeter();

    ConsoleIo& m_console;
    ShapeManager m_shapeManager;
};


#endif // APPLICATION_H
