#include <iostream>
#include <Eigen/Dense>

#include "optim.h"
#include "utils.h"

using namespace Eigen;
using namespace std;

int main(){
    int i = 0;
    MatrixXd a(2, 2);
    VectorXd b(2);
    double c = 0.0;
    double lr = 0.01;
    double beta_1 = 0.99;
    double beta_2 = 0.99;
    double eps = pow(10, -8);

    VectorXd x(2);

    a << 1.0,0.0, 
        0.0,1.0;
    b << 0.0,2.0;
    x << 2.0,1.0;
    Adam optim(a, b, c, lr, beta_1, beta_2, eps);

    double z = 0.01;

    //haha(z, z);

    return 0;
}