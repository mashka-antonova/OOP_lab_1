#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#include <iostream>
#include <limits>
#include <string>

#include "geometry_utils.h"

class ConsoleIO {
public:
    static std::string readString(const std::string& promt);
    static double readDouble(const std::string& promt);
    static int readInt(const std::string& promt);
    static Point readPoint(const std::string& promt);
    static void printMessage(const std::string& message);
    static void printMenu();
    static void printShapeChoice();

private:
    template <typename T>
    static T readNumericValue(const std::string& promt, const std::string& errorMessage) {
        bool isValid = false;
        T value;
        while (!isValid) {
            std::cout << promt;
            if (std::cin >> value) {
                isValid = true;
            } else {
                std::cout << errorMessage << std::endl;
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return value;
    }
};

#endif // CONSOLE_IO_H
