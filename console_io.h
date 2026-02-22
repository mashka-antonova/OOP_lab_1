#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#include <istream>
#include <sstream>
#include <constants.h>

#include "shapes.h"

class ConsoleIo{
public:
    ConsoleIo(std::istream& input, std::ostream& output);

    int readInt(const std::string& promt);
    double readDouble(const std::string& promt);
    MenuAction readMenuAction(const std::string& promt);

    std::string readNonEmptyString(const std::string& promt);
    Point readPoint(const std::string& promt);

    void printLine(const std::string& line);
    void printLines(const std::vector<std::string>& lines);

private:
    template <typename NumberType>
    NumberType readNumericValue(const std::string& promt, const std::string& errorMessage) {
        NumberType value;
        bool parsed = false;
        while(!parsed) {
            printLine(promt);
            std::string line;
            std::getline(m_input, line);
            std::istringstream stream(line);
            stream >> value;
            stream >> std::ws;
            parsed = stream && stream.eof();
            if (!parsed)
                printLine(errorMessage);
        }
        return value;
    }

    std::istream& m_input;
    std::ostream& m_output;
};

#endif // CONSOLE_IO_H
