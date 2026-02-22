#ifndef CONSTANTS_H
#define CONSTANTS_H

enum class MenuAction: int {
    Exit,
    AddShape,
    ListParameters,
    ListPerimeters,
    SumPerimeters,
    SortByPerimeters,
    DeleteByIndex,
    DeleteByPerimeter
};


constexpr int shapeCircle = 1;
constexpr int shapeRectangle = 2;
constexpr int shapeTriangle = 3;


constexpr int Precision = 3;
constexpr double Epsilon = 1e-12;
constexpr double Pi = 3.14159265358979323846;
constexpr double Two = 2.0;

#endif // CONSTANTS_H
