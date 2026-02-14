#include "nmtk/linearalgebra.hpp"
#include <cmath>

namespace nmtk {

std::tuple<Eigen::VectorXd,int,double>
cg(const Eigen::MatrixXd& A, const Eigen::VectorXd& b,
   int max_iters, double tol) {
  const int n = static_cast<int>(A.rows());
  Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
  Eigen::VectorXd r = b - A * x;
  Eigen::VectorXd p = r;
  double rsold = r.dot(r);

  int k = 0;
  for (; k < max_iters; ++k) {
    Eigen::VectorXd Ap = A * p;
    double alpha = rsold / p.dot(Ap);
    x += alpha * p;
    r -= alpha * Ap;
    double rsnew = r.dot(r);
    if (std::sqrt(rsnew) < tol) { ++k; rsold = rsnew; break; }
    p = r + (rsnew / rsold) * p;
    rsold = rsnew;
  }
  double resid = std::sqrt(rsold);
  return {x, k, resid};
}

} // namespace nmtk
