cmake_minimum_required(VERSION 3.14)
set(CMAKE_VERBOSE_MAKEFILE on)
project(cv_mat2)
 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
 
find_package(OpenCV REQUIRED) 
find_package(pybind11 REQUIRED)
set(PYTHON_INCLUDE_DIRS ${PYTHON_INCLUDE_DIRS} /usr/lib/python3/dist-packages/numpy/core/include)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${pybind11_INCLUDE_DIR})
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(/home/bcs/test/tkDNN/include/tkDNN)
include_directories(/usr/local/cuda-10.2/targets/aarch64-linux/include)


link_directories(/home/bcs/test/tkDNN/build)

SET(SOURCES
#  ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tkDNN_detection.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ndarray_converter.cpp
)
 
pybind11_add_module(example ${SOURCES})
target_link_libraries(example PRIVATE ${OpenCV_LIBS} libtkDNN.so)

