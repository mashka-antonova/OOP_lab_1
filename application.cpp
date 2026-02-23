#include "application.h"

#include "constants.h"
#include <iomanip>
#include <memory>
#include <sstream>
#include <stdexcept>

Application::Application(ConsoleIo& console) : m_console(console){}


//
int Application::run() {
    int exitCode = 0;
    bool running = true;
    while (running){
        try {
            printMenu();
            const int action = m_console.readInt("Enter menu item: ");
            exitCode = handleMenuAction(action);
            running = (exitCode == 0);
        } catch (const std::exception& exception) {
            m_console.printLine(std::string("Error: ") + exception.what());
            exitCode = 1;
            running = false;
        }
    }
    return exitCode;
}

int Application::handleMenuAction(int action) {
    int exitCode = 0;
    try {
        if (action == AddShape){
            m_shapeManager.addShape(creatShape());
            m_console.printLine("Shape added");
        } else if (action == ListParameters) {
            printParameterList();
        } else if (action == ListPerimeters) {
            printPerimeterList();
        } else if (action == SumPerimeters) {
            printTotalPerimeter();
        } else if (action == SortByPerimeters) {
            m_shapeManager.sortByPerimeterAscending();
            m_console.printLine("Sorting completed");
        } else if (action == DeleteByIndex) {
            deleteShapeByIndex();
        } else if (action == DeleteByPerimeter) {
            deleteShapeByPerimeter();
        } else if (action == Exit) {
            m_console.printLine("Exiting program");
            exitCode = 1;
        } else {
            m_console.printLine("Unknown menu item");
        }
    } catch (const std::exception& exception) {
        m_console.printLine(std::string("Error: ") + exception.what());
    }
    return exitCode;
}

void Application::printMenu() {
    m_console.printLine("==== Menu ====");
    m_console.printLine("1. Add a shape");
    m_console.printLine("2. Show numbered list of shapes with parameters");
    m_console.printLine("3. Show numbered list of shapes with perimeters");
    m_console.printLine("4. Show total perimeter");
    m_console.printLine("5. Sort shapes by perimeter ascending");
    m_console.printLine("6. Delete shape by index");
    m_console.printLine("7. Delete shapes with perimeter greater than threshold");
    m_console.printLine("0. Exit");
}

ShapePtr Application::creatShape() {
    m_console.printLine("Select shape type:");
    m_console.printLine("1. Circle");
    m_console.printLine("2. Rectangle");
    m_console.printLine("3. Triangle");

    const int shapeType = m_console.readInt("Your choice:");
    const std::string shapeName = m_console.readNonEmptyString("Enter shape custom name:");
    ShapePtr shape;
    if (shapeType == shapeCircle) {
        shape = std::make_unique<Circle>(shapeName, m_console.readPoint("Enter center coordinates:"),
                                         m_console.readDouble("Enter radius:"));
    } else if (shapeType == shapeRectangle) {
        shape = std::make_unique<Rectangle>(shapeName, m_console.readPoint("Enter top-left corner coordinates:"),
                                            m_console.readPoint("Enter bottom-right corner coordinates:"));
    } else if (shapeType == shapeTriangle) {
        shape = std::make_unique<Triangle>(shapeName, m_console.readPoint("Enter first coordinates:"),
                                           m_console.readPoint("Enter second coordinates:"),
                                           m_console.readPoint("Enter third coordinates:"));
    } else {
        throw std::invalid_argument("unknown shape type");
    }
    return shape;
}

void Application::printParameterList() {
    if (m_shapeManager.isEmpty())
        m_console.printLine("collection is empty");
    else
        m_console.printLines(m_shapeManager.buildParameterLines());
}

void Application::printPerimeterList() {
    if (m_shapeManager.isEmpty())
        m_console.printLine("collection is empty");
    else
        m_console.printLines(m_shapeManager.buildPerimeterLines());
}

void Application::printTotalPerimeter(){
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(Precision) << m_shapeManager.calclateTotalPerimeter();
    m_console.printLine("Total perimeter: " + stream.str());
}

void Application::deleteShapeByIndex(){
    const int index = m_console.readInt("Enter shape number to delete:");
    const bool removed = m_shapeManager.removeByIndex(index);
    m_console.printLine(removed ? "Shape deleted" : "Error: invalid index");
}

void Application::deleteShapeByPerimeter(){
    const double border = m_console.readDouble("Enter perimeter border:");
    const int removedCount = m_shapeManager.removeWithPerimeterGreaterThan(border);
    m_console.printLine("Shapes deleted: " + std::to_string(removedCount));
}
