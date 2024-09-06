from libcpp.string cimport string
from libcpp.vector cimport vector
from libcpp.memory cimport shared_ptr

cdef extern from "shape.h":
    cdef cppclass Shape:
        Shape(string name)
        string getName() const
        double calculateArea() const
    
    cdef cppclass Circle(Shape):
        Circle(string name, double radius)
        double calculateArea() const

    cdef cppclass Rectangle(Shape):
        Rectangle(string name, double length, double width)
        double calculateArea() const

    cdef cppclass Square(Rectangle):
        Square(string name, double side)

    cdef vector[shared_ptr[Shape]] getShapeList()

