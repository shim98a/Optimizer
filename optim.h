#ifndef _OPTIM_H_
#define _OPTIM_H_

#include <Eigen/Dense>

using namespace Eigen;

class Optimizer{
public:
    Optimizer(MatrixXd a, VectorXd b, double c, double lr);
    ~Optimizer();
    void set_coeffs(
        const MatrixXd& a, const VectorXd& b, const double & c
    );
    int get_niter();
    double cost(const VectorXd& x);
    virtual VectorXd step(const VectorXd& x);
protected:
    MatrixXd a;
    VectorXd b;
    double c;
    double lr;
    VectorXd grad(const VectorXd& x);
    static int n_iter;
};

class Adam : public Optimizer{
public:
    Adam(
        MatrixXd a,
        VectorXd b,
        double c,
        double lr,
        double beta_1,
        double beta_2,
        double eps
    );
    virtual ~Adam();
    VectorXd step(const VectorXd& x);
private:
    double beta_1;
    double beta_2;
    double eps;
    VectorXd m;
    VectorXd v;
};

#endif