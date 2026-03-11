#include "console_io.h"

std::string ConsoleIO::readString(const std::string& promt) {
    std::cout << promt;
    std::string input;
    std::getline(std::cin >> std::ws, input);
    return input;
}

int ConsoleIO::readInt(const std::string& promt) {
    return readNumericValue<int>(promt, "Wrong input! enter int number");
}

double ConsoleIO::readDouble(const std::string& promt) {
    return readNumericValue<double>(promt, "Wrong input! enter float number");
}

Point ConsoleIO::readPoint(const std::string& promt) {
    std::cout << "--- " << promt << " ---" << std::endl;
    Point point;
    point.x = readDouble("enter X:");
    point.y = readDouble("enter Y:");
    return point;
}

void ConsoleIO::printMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void ConsoleIO::printMenu() {
    std::cout << "\n========== MENU ==========" << std::endl
    << "1. Add a shape" << std::endl
    << "2. List shapes with parameters" << std::endl
    << "3. List shapes with perimeters" << std::endl
    << "4. Calculate total perimeter" << std::endl
    << "5. Sort shapes by perimeter" << std::endl
    << "6. Remove shape by number" << std::endl
    << "7. Remove shapes by perimeter border" << std::endl
    << "0. Exit" << std::endl
    << "==========================" << std::endl;
}

void ConsoleIO::printShapeChoice() {
    printMessage("\nSelect shape type:");
    printMessage("1. Circle\n2. Rectangle\n3. Triangle\n4. Convex polygon");
}
