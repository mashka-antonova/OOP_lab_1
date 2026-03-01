#include "application.h"

#include <format>

Application::Application() : creator(console), isRunning(false) {
    initActions();
}

void Application::initActions() {

    actions[MenuAction::Exit] = std::bind(&Application::onExit, this);
    actions[MenuAction::AddShape] = std::bind(&Application::onAddShape, this);
    actions[MenuAction::PrintParameters] = std::bind(&Application::onPrintParameters, this);
    actions[MenuAction::PrintPerimeters] = std::bind(&Application::onPrintPerimeters, this);
    actions[MenuAction::PrintTotalPerimeter] = std::bind(&Application::onPrintTotalPerimeter, this);
    actions[MenuAction::SortByPerimeter] = std::bind(&Application::onSortShapes, this);
    actions[MenuAction::RemoveByIndex] = std::bind(&Application::onRemoveByIndex, this);
    actions[MenuAction::RemoveByBorder] = std::bind(&Application::onRemoveByBorder, this);
}

void Application::run() {
    isRunning = true;

    while (isRunning) {
        console.printMenu();
        MenuAction choice = static_cast<MenuAction>(console.readInt("Enter choice: "));
        auto it = actions.find(choice);
        if (it != actions.end())
            it->second();
        else
            console.printMessage("unknown option, please try again");
    }
}

void Application::onExit() {
    isRunning = false;
    console.printMessage("---EXIT---");
}

void Application::onAddShape() {
    console.printShapeChoice();
    ShapeType selectedType = static_cast<ShapeType>(console.readInt("Choice: "));
    try {
        std::unique_ptr<Shape> shape = creator.creatShape(selectedType);
        if (shape){
            manager.addShape(std::move(shape));
            console.printMessage("Shape added successfully.");
        }
    } catch (const std::exception& e) {
        console.printMessage(std::format("Error creating shape: {}", e.what()));
    }
}

void Application::onPrintParameters() {
    std::vector<std::string> list = manager.buildPerameterList();
    if (list.empty()) {
        console.printMessage("the collection is empty");
    } else {
        for (const std::string& line : list) {
            console.printMessage(line);
        }
    }
}

void Application::onPrintPerimeters() {
    std::vector<std::string> list = manager.buildPerimeterList();
    if (list.empty()) {
        console.printMessage("the collection is empty");
    } else {
        for (const std::string& line : list) {
            console.printMessage(line);
        }
    }
}

void Application::onPrintTotalPerimeter() {
    double total = manager.calculateTotalPerimeter();
    console.printMessage(std::format("Total perimeter: {:.3f}", total));
}

void Application::onSortShapes() {
    manager.sortByPerimeter();
    console.printMessage("Shapes have been sorted by perimeter.");
}

void Application::onRemoveByIndex() {
    int index = console.readInt("Enter shape number to remove: ");
    if (manager.removeByIndex(index)) {
        console.printMessage("shape removed.");
    } else {
        console.printMessage("error: incorrect shape number");
    }
}

void Application::onRemoveByBorder() {
    double threshold = console.readDouble("Enter perimeter border: ");
    int removedCount = manager.removeByPerimeterGreaterThan(threshold);
    console.printMessage(std::format("removed {} shapes.", removedCount));
}
