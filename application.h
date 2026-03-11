#ifndef APPLICATION_H
#define APPLICATION_H

#include <map>
#include <functional>
#include <typeindex>
#include <typeinfo>
#include "shape_manager.h"
#include "shape_creator.h"
#include "menu_action.h"

class Application {
public:
    Application(ShapeManager manager, ShapeCreator creator);
    void run();

private:
    ShapeManager shapeManager;
    ShapeCreator shapeCreator;

    std::map<int, std::type_index> menuToShapeType;
    std::map<MenuAction, std::function<void()>> actions;
    void initActions();
    void initTypes();

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
