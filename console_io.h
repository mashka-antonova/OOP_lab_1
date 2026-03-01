#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#include <string>
#include <iostream>
#include <limits>
#include "geometry_utils.h"

class ConsoleIO {
public:
    std::string readString(const std::string& promt);
    double readDouble(const std::string& promt);
    int readInt(const std::string& promt);
    Point readPoint(const std::string& promt);
    void printMessage(const std::string& message);
    void printMenu();
    void printShapeChoice();

private:
    template <typename T>
    T readNumericValue(const std::string& promt, const std::string& errorMessage) {
        bool isValid = false;
        T value;
        while (!isValid) {
            std::cout << promt;
            if (std::cin >> value)
                isValid = true;
            else {
                std::cout << errorMessage << std::endl;
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return value;
    }
};

#endif // CONSOLE_IO_H
