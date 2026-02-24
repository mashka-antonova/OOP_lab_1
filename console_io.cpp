#include "console_io.h"

#include <algorithm>
#include <cctype>


ConsoleIo::ConsoleIo(std::istream& input, std::ostream& output) : input(input), output(output){}

int ConsoleIo::readInt(const std::string& promt) {
    return readNumericValue<int>(promt, "please enter an integer");
}

double ConsoleIo::readDouble(const std::string& promt) {
    return readNumericValue<double>(promt, "please enter a floating number");
}

std::string ConsoleIo::readNonEmptyString(const std::string& promt) {
    std::string value;
    bool valid = false;
    while (!valid){
        printLine(promt);
        if (!std::getline(input, value)) {
            throw std::runtime_error("input stream closed");
        }

        const bool blankOnly = std::all_of(value.begin(), value.end(), [](unsigned char symbol) {
            return std::isspace(symbol) != 0;
        });
        valid = !value.empty() && !blankOnly;
        if (!valid)
            printLine("string must not be empty or blank");
    }
    return value;
}

Point ConsoleIo::readPoint(const std::string& promt){
    printLine(promt);
    Point point;
    point.x = readDouble("x:");
    point.y = readDouble("y:");
    return point;
}

void ConsoleIo::printLine(const std::string& line) {
    output << line << '\n';
    output.flush();
}

void ConsoleIo::printLines(const std::vector<std::string>& lines) {
    for (const std::string& line : lines) {
        printLine(line);
    }
}
