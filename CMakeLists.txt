cmake_minimum_required(VERSION 3.18)
project(nmtk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(pybind11 CONFIG REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_library(nmtk STATIC
  src/root.cpp
  src/ode.cpp
  src/linearalgebra.cpp
)

target_include_directories(nmtk PUBLIC include)
target_link_libraries(nmtk PUBLIC Eigen3::Eigen)

pybind11_add_module(_core MODULE src/pybind_module.cpp)
target_include_directories(_core PRIVATE include)
target_link_libraries(_core PRIVATE nmtk)

install(TARGETS _core LIBRARY DESTINATION nmtk)
