#include "console_io.h"

#include <cctype>


ConsoleIo::ConsoleIo(std::istream& input, std::ostream& output) : m_input(input), m_output(output){}

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
        std::getline(m_input, value);
        valid = !value.empty();
        if (!valid)
            printLine("string must not be empty");
    }
    return value;
}

Point ConsoleIo::readPoint(const std::string& promt){
    printLine(promt);
    Point point;
    point.x = readDouble(" x:");
    point.y = readDouble(" y:");
    return point;
}

void ConsoleIo::printLine(const std::string& line) {
    m_output << line << '\n';
    m_output.flush();
}

void ConsoleIo::printLines(const std::vector<std::string>& lines) {
    for (const std::string& line : lines) {
        printLine(line);
    }
}
