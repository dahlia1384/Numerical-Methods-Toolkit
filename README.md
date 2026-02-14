# Numerical Methods Toolkit

Numerical Methods Toolkit (NMTK) provides core numerical algorithms in **C++**, exposes them through **Python bindings**, and now includes a lightweight **Dart web frontend** for interactive demos.

## What is included

- **Root finding**: Newton and Bisection
- **ODE solving**: Scalar RK4 integrator
- **Linear algebra**: Conjugate Gradient for SPD systems (Eigen-backed)
- **Python API**: pybind11 module wrapping the C++ core
- **Dart frontend**: browser UI to explore Newton and RK4 behavior interactively

---

## Build the C++ core + Python module

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
pip install -e .
```

### Quick Python smoke test

```python
import nmtk
opts = nmtk.RootOptions()
opts.max_iters = 50
res = nmtk.newton(lambda x: x**3 - x - 2, lambda x: 3*x*x - 1, 1.5, opts)
print(res.root, res.converged)
```

---

## Dart frontend (web)

The frontend is in `frontend/` and can be run as a static web app compiled with Dart.

```bash
cd frontend
dart pub get
dart compile js web/main.dart -O2 -o web/main.dart.js
python -m http.server 8080
# open http://localhost:8080/web/
```

It demonstrates:
- Newton's method for `x^3 - x - 2 = 0`
- RK4 for `y' = y - t^2 + 1, y(0)=0.5`

---

## Project layout

- `include/nmtk/*.hpp`: C++ public headers
- `src/*.cpp`: C++ implementations and pybind module
- `python/nmtk/__init__.py`: Python package surface
- `frontend/`: Dart web app

## License

MIT
