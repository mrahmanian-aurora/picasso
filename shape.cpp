#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "shape.h"

Shape::Shape(std::string name): m_name(name){}
std::string Shape::getName() const {return m_name;}

Circle::Circle(std::string name, double radius): Shape(name), m_radius(radius){}
double Circle:: calculateArea() const {return 3.14 * m_radius * m_radius;}

Rectangle::Rectangle(std::string name, double length, double width): Shape(name), m_length(length), m_width(width){}
double Rectangle::calculateArea() const {return m_length * m_width;}

Square::Square(std::string name, double side): Rectangle(name, side, side) {}

std::shared_ptr<Shape> getShapePtr(){
    return std::make_shared<Circle>("my circle", 1.0);   
}

std::vector<std::shared_ptr<Shape> > getShapeList() {
    std::vector<std::shared_ptr<Shape> > shapeList;
    shapeList.push_back(std::make_shared<Circle>("my circle", 1.0));
    shapeList.push_back(std::make_shared<Rectangle>("my rectangle", 1.0, 2.0));
    shapeList.push_back(std::make_shared<Square>("my square", 1.0));
    return shapeList;
}
