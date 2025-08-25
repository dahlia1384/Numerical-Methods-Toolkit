#pragma once
#include <functional>
#include <cmath>

namespace nmtk {

struct RootResult {
  double root;
  int iters;
  bool converged;
  double residual;
};

struct RootOptions {
  int max_iters = 50;
  double tol = 1e-12;
};

RootResult newton(const std::function<double(double)>& f,
                  const std::function<double(double)>& df,
                  double x0,
                  RootOptions opts = {});

RootResult bisection(const std::function<double(double)>& f,
                     double a, double b,
                     RootOptions opts = {});

} // dahlia1384
