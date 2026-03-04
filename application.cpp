#include "application.h"

#include <format>
#include "console_io.h"

Application::Application() : shapeManager(), shapeCreator(), isRunning(false) {
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
        ConsoleIO::printMenu();
        MenuAction choice = static_cast<MenuAction>(ConsoleIO::readInt("Enter choice: "));
        auto it = actions.find(choice);
        if (it != actions.end())
            it->second();
        else
            ConsoleIO::printMessage("unknown option, please try again");
    }
}

void Application::onExit() {
    isRunning = false;
    ConsoleIO::printMessage("----EXIT----");
}

void Application::onAddShape() {
    ConsoleIO::printShapeChoice();
    ShapeType selectedType = static_cast<ShapeType>(ConsoleIO::readInt("Choice: "));
    try {
        std::unique_ptr<Shape> shape = shapeCreator.creatShape(selectedType);
        if (shape){
            shapeManager.addShape(std::move(shape));
            ConsoleIO::printMessage("Shape added successfully.");
        }
    } catch (const std::exception& e) {
        ConsoleIO::printMessage(std::format("Error creating shape: {}", e.what()));
    }
}

void Application::onPrintParameters() {
    std::vector<std::string> list = shapeManager.buildPerameterList();
    if (list.empty()) {
        ConsoleIO::printMessage("the collection is empty");
    } else {
        for (const std::string& line : list) {
            ConsoleIO::printMessage(line);
        }
    }
}

void Application::onPrintPerimeters() {
    std::vector<std::string> list = shapeManager.buildPerimeterList();
    if (list.empty()) {
        ConsoleIO::printMessage("the collection is empty");
    } else {
        for (const std::string& line : list) {
            ConsoleIO::printMessage(line);
        }
    }
}

void Application::onPrintTotalPerimeter() {
    double total = shapeManager.calculateTotalPerimeter();
    ConsoleIO::printMessage(std::format("Total perimeter: {:.3f}", total));
}

void Application::onSortShapes() {
    shapeManager.sortByPerimeter();
    ConsoleIO::printMessage("Shapes have been sorted by perimeter.");
}

void Application::onRemoveByIndex() {
    int index = ConsoleIO::readInt("Enter shape number to remove: ");
    if (shapeManager.removeByIndex(index)) {
        ConsoleIO::printMessage("shape removed.");
    } else {
        ConsoleIO::printMessage("error: incorrect shape number");
    }
}

void Application::onRemoveByBorder() {
    double border = ConsoleIO::readDouble("Enter perimeter border: ");
    int removedCount = shapeManager.removeByPerimeterGreaterThan(border);
    ConsoleIO::printMessage(std::format("removed {} shapes.", removedCount));
}
