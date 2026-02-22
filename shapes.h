#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <memory>
#include <vector>

struct Point{
    double x;
    double y;
};

class Shape{
public:
    explicit Shape(std::string name);
    virtual ~Shape() = default;

    const std::string& name() const;
    virtual std::string typeName() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string parametersToString() const = 0;

private:
    std::string m_name;
};

class Circle final: public Shape{
public:
    Circle(std::string name, Point center, double radius);
    std::string typeName() const override;
    virtual double perimeter() const override;
    virtual std::string parametersToString() const override;

private:
    Point m_center;
    double m_radius;
};

class Rectangle final: public Shape{
public:
    Rectangle(std::string name, Point leftTop, Point rightBottom);
    std::string typeName() const override;
    double perimeter() const override;
    std::string parametersToString() const override;

private:
    Point m_leftTop;
    Point m_rightBottom;
};

class Triangle final: public Shape{
public:
    Triangle(std::string name, Point first, Point second, Point third);
    std::string typeName() const override;
    double perimeter() const override;
    std::string parametersToString() const override;

private:
    Point m_first;
    Point m_second;
    Point m_third;
};

using ShapePtr = std::unique_ptr<Shape>;
using ShapeCollection = std::vector<ShapePtr>;

#endif // SHAPES_H
