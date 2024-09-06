#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Shape{
public:
    Shape(std::string name);
    std::string getName() const;
    virtual double calculateArea() const = 0;
    virtual ~Shape() = default;
protected:
    std::string m_name;
};

class Circle: public Shape{
public:
    Circle(std::string name, double radius);
    double calculateArea() const;
protected:
    double m_radius;
};

class Rectangle: public Shape{
public:
    Rectangle(std::string name, double length, double width);
    double calculateArea() const;
protected:
    double m_length;
    double m_width;
};

class Square: public Rectangle{
public:
    Square(std::string name, double side);
};

std::shared_ptr<Shape> getShapePtr();
std::vector<std::shared_ptr<Shape> > getShapeList();
