# Numerical Methods Toolkit

A collection of algorithms for **root finding**, **ODE solving**, and **linear algebra** — implemented in **C++** (for speed) with **Python** bindings (for usability). Ideal for high-performance scientific computing, teaching, and quick experiments.

> C++ core for performance • Python API for productivity

---

## Features

- **Root Finding:** Bisection, Newton–Raphson, Secant (with bracketing helpers & derivative-free options)
- **ODE Solvers:** Explicit Euler, RK2, classic RK4, adaptive RK45 (Dormand–Prince) with event hooks
- **Linear Algebra:** Dense (LU, QR, Cholesky) and iterative (CG, GMRES) on lightweight matrix types
- **Bindings:** Clean Python wrappers around the C++ core (via pybind11)
- **Utilities:** Step-size control, stopping criteria, logging & timing macros

---

## Why C++ *and* Python?

- **C++**: tight loops, SIMD-friendly code paths, predictable performance
- **Python**: fast prototyping, notebooks, easy composability with NumPy / SciPy

---

## Install

### Clone & Build (recommended for now)
```bash
git clone https://github.com/<you>/numerical-methods-toolkit.git
cd numerical-methods-toolkit
# Build C++ library
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
# (Optional) install system-wide
# sudo cmake --install build

# Build Python package (editable)
pip install -U pip
pip install -e .
