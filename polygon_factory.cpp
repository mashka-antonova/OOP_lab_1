#include "polygon_factory.h"

#include "console_io.h"
#include "polygon.h"

#include <format>
#include <stdexcept>
#include <vector>

std::unique_ptr<Shape> PolygonFactory::creat() {
    std::string name = ConsoleIO::readString("Enter polygon name: ");
    int peaksCount = ConsoleIO::readInt("Enter peaks count (>= 3): ");
    if (peaksCount < MIN_COUNT_OF_PEAKS)
        throw std::invalid_argument("polygon must have at least 3 peaks");

    std::vector<Point> peaks;
    peaks.reserve(peaksCount);

    for (int i = 0; i < peaksCount; ++i)
        peaks.push_back(ConsoleIO::readPoint(std::format("Peak {}", i + 1)));

    return std::make_unique<Polygon>(name, std::move(peaks));
}
