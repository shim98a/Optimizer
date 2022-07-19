#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include "optim.h"

using namespace Eigen;

int Optimizer::n_iter = 0;

// Constructor, De-constructor
Optimizer::Optimizer(MatrixXd a, VectorXd b, double c, double lr)
    :a(a), b(b), c(c), lr(lr){}
Optimizer::~Optimizer(){}

// Public methods
void Optimizer::set_coeffs(
    const MatrixXd& a_,
    const VectorXd& b_,
    const double &c_
){
    a = a_; b = b_; c = c_;
}

int Optimizer::get_niter()
{
    return n_iter;
}

double Optimizer::cost(const VectorXd& x)
{
    return x.dot(a * x) + x.dot(b) + c;
}

VectorXd Optimizer::step(const VectorXd& x)
{
    n_iter++;
    return x - lr * grad(x);
}

// Private methods
VectorXd Optimizer::grad(const VectorXd& x)
{
    return 2.0 * a * x + b;
}

////////////
//  Adam ///
////////////

Adam::Adam(
    MatrixXd a,
    VectorXd b,
    double c,
    double lr,
    double beta_1,
    double beta_2,
    double eps
):Optimizer(a, b, c, lr), beta_1(beta_1), beta_2(beta_2), eps(eps)
{
    m = VectorXd::Zero(b.size());
    v = VectorXd::Zero(b.size());
}

Adam::~Adam(){}

VectorXd Adam::step(const VectorXd& x)
{
    int i;
    VectorXd g(x.size());
    VectorXd x_next(x.size());
    double m_hat;
    double v_hat;

    n_iter++;
    g << grad(x);

    for(i = 0; i < x.size(); i++){
        m[i] = beta_1 * m[i] + (1 - beta_1) * g[i];
        v[i] = beta_2 * v[i] + (1 - beta_2) * pow(g[i], 2);
        m_hat = m[i] / (1.0 - pow(beta_1, n_iter));
        v_hat = v[i] / (1.0 - pow(beta_2, n_iter));
        x_next[i] = x[i] - lr * m_hat / (sqrt(v_hat) + eps);
    }
    return x_next;
}
