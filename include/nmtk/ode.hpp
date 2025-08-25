#pragma once
#include <vector>
#include <functional>

namespace nmtk {

struct ODEResult {
  std::vector<double> ts;
  std::vector<double> ys; // scalar ODE
};

ODEResult rk4(const std::function<double(double,double)>& f,
              double t0, double y0,
              double dt, int steps);

} // namespace nmtk
