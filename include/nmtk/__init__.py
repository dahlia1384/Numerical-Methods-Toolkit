"""
Numerical Methods Toolkit — Python API.
Backed by a C++ core via pybind11.
"""
from ._core import (  # type: ignore
    RootOptions, RootResult, newton, bisection,
    ODEResult, rk4,
    cg,
)

__all__ = [
    "RootOptions", "RootResult", "newton", "bisection",
    "ODEResult", "rk4",
    "cg",
]
