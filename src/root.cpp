#include "nmtk/root.hpp"
#include <stdexcept>
#include <limits>

namespace nmtk {

RootResult newton(const std::function<double(double)>& f,
                  const std::function<double(double)>& df,
                  double x0,
                  RootOptions opts) {
  RootResult R{ x0, 0, false, std::numeric_limits<double>::infinity() };
  double x = x0;
  for (int k = 1; k <= opts.max_iters; ++k) {
    double fx = f(x);
    double dfx = df(x);
    if (std::abs(dfx) == 0.0) break;
    double x1 = x - fx / dfx;
    R.residual = std::abs(fx);
    if (std::abs(x1 - x) <= opts.tol * (1.0 + std::abs(x1))) {
      R.root = x1; R.iters = k; R.converged = true; return R;
    }
    x = x1;
  }
  R.root = x;
  R.iters = opts.max_iters;
  return R;
}

RootResult bisection(const std::function<double(double)>& f,
                     double a, double b,
                     RootOptions opts) {
  double fa = f(a), fb = f(b);
  if (fa * fb > 0.0) throw std::invalid_argument("bisection: f(a)*f(b) > 0");
  double left = a, right = b, mid = 0.5 * (a + b);
  RootResult R{ mid, 0, false, std::abs(f(mid)) };
  for (int k = 1; k <= opts.max_iters; ++k) {
    mid = 0.5 * (left + right);
    double fm = f(mid);
    R.residual = std::abs(fm);
    if (std::abs(right - left) <= 2.0 * opts.tol * (1.0 + std::abs(mid))) {
      R.root = mid; R.iters = k; R.converged = true; return R;
    }
    if (fa * fm <= 0.0) { right = mid; fb = fm; }
    else               { left = mid;  fa = fm; }
  }
  R.root = mid; R.iters = opts.max_iters; return R;
}

} // dahlia1384
