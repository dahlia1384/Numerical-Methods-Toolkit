#include "nmtk/ode.hpp"

namespace nmtk {

ODEResult rk4(const std::function<double(double,double)>& f,
              double t0, double y0,
              double dt, int steps) {
  ODEResult R;
  R.ts.reserve(steps + 1);
  R.ys.reserve(steps + 1);
  double t = t0, y = y0;
  R.ts.push_back(t); R.ys.push_back(y);
  for (int i = 0; i < steps; ++i) {
    double k1 = f(t, y);
    double k2 = f(t + 0.5*dt, y + 0.5*dt*k1);
    double k3 = f(t + 0.5*dt, y + 0.5*dt*k2);
    double k4 = f(t + dt,     y + dt*k3);
    y += (dt/6.0) * (k1 + 2*k2 + 2*k3 + k4);
    t += dt;
    R.ts.push_back(t);
    R.ys.push_back(y);
  }
  return R;
}

} // namespace nmtk
