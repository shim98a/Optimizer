#include <iostream>
#include <vector>

#include "quadratic.hpp"
#include "gradient_descent.hpp"

using namespace std;

int main()
{
    std::vector<std::vector<double>> A = {{1,2},{2,1}};
    std::vector<double> b = {1,2};

    QuadraticCostFunction cf(A, b);
    GradientDescent opt(0.1);

    std::vector<double> params = {1, 1};
    std::vector<double> new_params = opt.step(cf, params);
    cout << new_params[0] << endl;
}