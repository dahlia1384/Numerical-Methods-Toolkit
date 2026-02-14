#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>
#include "nmtk/root.hpp"
#include "nmtk/ode.hpp"
#include "nmtk/linearalgebra.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
  m.doc() = "Numerical Methods Toolkit — C++ core bindings";

  // root
  py::class_<nmtk::RootOptions>(m, "RootOptions")
    .def(py::init<>())
    .def_readwrite("max_iters", &nmtk::RootOptions::max_iters)
    .def_readwrite("tol", &nmtk::RootOptions::tol);

  py::class_<nmtk::RootResult>(m, "RootResult")
    .def_readonly("root", &nmtk::RootResult::root)
    .def_readonly("iters", &nmtk::RootResult::iters)
    .def_readonly("converged", &nmtk::RootResult::converged)
    .def_readonly("residual", &nmtk::RootResult::residual);

  m.def("newton", &nmtk::newton,
        py::arg("f"), py::arg("df"), py::arg("x0"), py::arg("opts") = nmtk::RootOptions{});
  m.def("bisection", &nmtk::bisection,
        py::arg("f"), py::arg("a"), py::arg("b"), py::arg("opts") = nmtk::RootOptions{});

  // ode
  py::class_<nmtk::ODEResult>(m, "ODEResult")
    .def_readonly("ts", &nmtk::ODEResult::ts)
    .def_readonly("ys", &nmtk::ODEResult::ys);

  m.def("rk4", &nmtk::rk4,
        py::arg("f"), py::arg("t0"), py::arg("y0"), py::arg("dt"), py::arg("steps"));

  // linalg
  m.def("cg", &nmtk::cg, py::arg("A"), py::arg("b"),
        py::arg("max_iters") = 1000, py::arg("tol") = 1e-10,
        "Conjugate Gradient: returns (x, iters, residual)");
}
