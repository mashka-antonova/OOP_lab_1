#include "application.h"
#include "console_io.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "polygon.h"
#include <format>


Application::Application(ShapeManager manager, ShapeCreator creator):
    shapeManager(std::move(manager)),
    shapeCreator(std::move(creator))
{
    initActions();
    initTypes();
}

void Application::initActions() {
    actions[MenuAction::Exit] = std::bind(&Application::onExit, this); //
    actions[MenuAction::AddShape] = std::bind(&Application::onAddShape, this);
    actions[MenuAction::PrintParameters] = std::bind(&Application::onPrintParameters, this);
    actions[MenuAction::PrintPerimeters] = std::bind(&Application::onPrintPerimeters, this);
    actions[MenuAction::PrintTotalPerimeter] = std::bind(&Application::onPrintTotalPerimeter, this);
    actions[MenuAction::SortByPerimeter] = std::bind(&Application::onSortShapes, this);
    actions[MenuAction::RemoveByIndex] = std::bind(&Application::onRemoveByIndex, this);
    actions[MenuAction::RemoveByBorder] = std::bind(&Application::onRemoveByBorder, this);
}

void Application::initTypes() {
    menuToShapeType.emplace(1, typeid(Circle));
    menuToShapeType.emplace(2, typeid(Rectangle));
    menuToShapeType.emplace(3, typeid(Triangle));
    menuToShapeType.emplace(4, typeid(Polygon));
}

void Application::run() {
    while (true) {
        ConsoleIO::printMenu();
        MenuAction choice = static_cast<MenuAction>(ConsoleIO::readInt("Enter choice: "));

        if (choice == MenuAction::Exit) {
            onExit();
            break;
        }

        auto it = actions.find(choice);
        if (it != actions.end())
            it->second();
        else
            ConsoleIO::printMessage("unknown option, please try again");
    }
}

void Application::onExit() {;
    ConsoleIO::printMessage("----EXIT----");
}

void Application::onAddShape() {
    ConsoleIO::printShapeChoice();
    int typeChoice = ConsoleIO::readInt("Choice: ");

    auto it = menuToShapeType.find(typeChoice);
    if (it != menuToShapeType.end()) {
        try {
            std::unique_ptr<Shape> shape = shapeCreator.createShape(it->second);
            if (shape) {
                shapeManager.addShape(std::move(shape));
                ConsoleIO::printMessage("Shape added successfully");
            }
        } catch (const std::exception& e) {
            ConsoleIO::printMessage(std::format("Error: {}", e.what()));
        }
    } else
        ConsoleIO::printMessage("invalid shape type");
}

void Application::onPrintParameters() {
    std::vector<std::string> list = shapeManager.buildParameterList();
    if (list.empty()) {
        ConsoleIO::printMessage("the collection is empty");
    } else {
        for (const std::string& line : list)
            ConsoleIO::printMessage(line);
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
        ConsoleIO::printMessage("shape removed");
    } else {
        ConsoleIO::printMessage("error: incorrect shape number");
    }
}

void Application::onRemoveByBorder() {
    double border = ConsoleIO::readDouble("Enter perimeter border: ");
    int removedCount = shapeManager.removeByPerimeterGreaterThan(border);
    ConsoleIO::printMessage(std::format("removed {} shapes.", removedCount));
}
