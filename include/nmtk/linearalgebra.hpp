#pragma once
#include <Eigen/Core>
#include <tuple>

namespace nmtk {

// Conjugate Gradient for SPD A
std::tuple<Eigen::VectorXd,int,double>
cg(const Eigen::MatrixXd& A, const Eigen::VectorXd& b,
   int max_iters = 1000, double tol = 1e-10);

} // namespace nmtk
