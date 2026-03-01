#ifndef APPLICATION_H
#define APPLICATION_H

#include <map>
#include <functional>

#include "shape_manager.h"
#include "console_io.h"
#include "shape_creator.h"
#include "menu_action.h"

class Application {
public:
    Application();
    void run();

private:
    ShapeManager manager;
    ConsoleIO console;
    ShapeCreator creator;
    bool isRunning;

    std::map<MenuAction, std::function<void()>> actions;
    void initActions();

    void onExit();
    void onAddShape();
    void onPrintParameters();
    void onPrintPerimeters();
    void onPrintTotalPerimeter();
    void onSortShapes();
    void onRemoveByIndex();
    void onRemoveByBorder();
};

#endif // APPLICATION_H
