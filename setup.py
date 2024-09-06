from setuptools import setup, Extension
from Cython.Build import cythonize
import os

# Set the paths to include directories and library directories
include_dirs = [os.path.join(os.getcwd())]  # This assumes the current directory contains the header files

# Define the extension module
extensions = [
    Extension(
        name="shapes",
        sources=["shapes.pyx", "shape.cpp"],  # Cython file and C++ file
        language="c++",  # Specifies the language of the extension
        include_dirs=include_dirs,
        extra_compile_args=["-std=c++11"],  # Use C++11 standard
    )
]

# Setup function to build the module
setup(
    name="shapes",
    ext_modules=cythonize(extensions),  # Use cythonize to compile the Cython file
    zip_safe=False,
)
