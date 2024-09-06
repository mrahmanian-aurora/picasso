from libcpp.string cimport string
from libcpp.vector cimport vector
from libcpp.memory cimport shared_ptr
from shapes cimport Shape, getShapeList

cdef class CyShape:
    cdef shared_ptr[Shape] _ptr
    def get_name(self):
        if self._ptr:
            return self._ptr.get().getName()

    def calculate_area(self):
        if self._ptr:
            return self._ptr.get().calculateArea() 

cdef create_cy_shape(shared_ptr[Shape] shared_ptr):
    cdef CyShape cy_shape = CyShape()
    cy_shape._ptr = shared_ptr
    return cy_shape

# Function to retrieve the list of shapes from C++
def get_shape_list():
    cdef vector[shared_ptr[Shape]] shape_list = getShapeList()  # Retrieve shape list from C++
    py_shape_list = []

    for i in range(shape_list.size()):
        py_shape_list.append(create_cy_shape(shape_list[i]))  # Append CyShape object to Python list

    return py_shape_list
