#include "application.h"

#include "constants.h"
#include <iomanip>
#include <memory>
#include <sstream>
#include <stdexcept>

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

Application::Application(ConsoleIo& console) : console(console){
    void initHandlers();
}

void Application::initHandlers() {
    handlers[AddShape] = std::bind(&Application::addShape, this);
    handlers[ListParameters] = std::bind(&Application::printParameterList, this);
    handlers[ListPerimeters] = std::bind(&Application::printPerimeterList, this);
    handlers[SumPerimeters] = std::bind(&Application::printTotalPerimeter, this);
    handlers[SortByPerimeters] = std::bind(&Application::sortByPerimeters, this);
    handlers[DeleteByIndex] = std::bind(&Application::deleteShapeByIndex, this);
    handlers[DeleteByPerimeter] = std::bind(&Application::deleteShapeByPerimeter, this);
    handlers[Exit] = std::bind(&Application::exit, this);
}

int Application::run() {
    int exitCode = 0;
    bool running = true;
    while (running){
        try {
            printMenu();
            const int action = console.readInt("Enter menu item: ");
            exitCode = handleMenuAction(action);
            running = (action != Exit);
        } catch (const std::exception& exception) {
            console.printLine(std::string("Error: ") + exception.what());
            exitCode = 1;
        }
    }
    return exitCode;
}

int Application::handleMenuAction(int action) {
    auto it = handlers.find(action);
    if (it != handlers.end()) {
        try {
            it->second();
        } catch (const std::exception& exception) {
            console.printLine(std::string("Error: ") + exception.what());
        }
    } else {
        console.printLine("Unknown menu item");
    }
    return 0;
}

void Application::printMenu() {
    console.printLine("==== Menu ====");
    console.printLine("1. Add a shape");
    console.printLine("2. Show numbered list of shapes with parameters");
    console.printLine("3. Show numbered list of shapes with perimeters");
    console.printLine("4. Show total perimeter");
    console.printLine("5. Sort shapes by perimeter ascending");
    console.printLine("6. Delete shape by index");
    console.printLine("7. Delete shapes with perimeter greater than threshold");
    console.printLine("0. Exit");
}

void Application::printShapeChoice() {
    console.printLine("Select shape type:");
    console.printLine("1. Circle");
    console.printLine("2. Rectangle");
    console.printLine("3. Triangle");
}

void Application::addShape() {
    shapeManager.addShape(createShape());
    console.printLine("Shape added");
}

void Application::sortByPerimeters() {
    shapeManager.sortByPerimeterAscending();
    console.printLine("Sorting completed");
}

void Application::exit() {
    console.printLine("Exiting program");
}


std::unique_ptr<Shape> Application::createShape() {
    printShapeChoice();
    const int shapeType = console.readInt("Your choice:"); //
    const std::string shapeName = console.readNonEmptyString("Enter shape custom name:");
    std::unique_ptr<Shape> shape;
    if (shapeType == shapeCircle) {
        const Point center = console.readPoint("Enter center coordinates:");
        const double radius = console.readDouble("Enter radius:");
        shape = std::make_unique<Circle>(shapeName, center, radius);
    } else if (shapeType == shapeRectangle) {
        const Point leftTop = console.readPoint("Enter top-left corner coordinates:");
        const Point rightBottom = console.readPoint("Enter bottom-right corner coordinates:");
        shape = std::make_unique<Rectangle>(shapeName, leftTop, rightBottom);
    } else if (shapeType == shapeTriangle) {
        const Point first = console.readPoint("Enter first coordinates:");
        const Point second = console.readPoint("Enter second coordinates:");
        const Point third = console.readPoint("Enter third coordinates:");
        shape = std::make_unique<Triangle>(shapeName, first, second, third);
    } else {
        throw std::invalid_argument("unknown shape type");
    }
    return shape;
}

void Application::printParameterList() {
    if (shapeManager.isEmpty())
        console.printLine("collection is empty");
    else
        console.printLines(shapeManager.buildParameterLines());
}

void Application::printPerimeterList() {
    if (shapeManager.isEmpty())
        console.printLine("collection is empty");
    else
        console.printLines(shapeManager.buildPerimeterLines());
}

void Application::printTotalPerimeter(){
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(Precision) << shapeManager.calclateTotalPerimeter();
    console.printLine("Total perimeter: " + stream.str());
}

void Application::deleteShapeByIndex(){
    const int index = console.readInt("Enter shape number to delete:");
    const bool removed = shapeManager.removeByIndex(index);
    console.printLine(removed ? "Shape deleted" : "Error: invalid index");
}

void Application::deleteShapeByPerimeter(){
    const double border = console.readDouble("Enter perimeter border:");
    const int removedCount = shapeManager.removeWithPerimeterGreaterThan(border);
    console.printLine("Shapes deleted: " + std::to_string(removedCount));
}
