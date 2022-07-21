#include <iostream>
#include <vector>

#include "quadratic.hpp"
#include "gradient_descent.hpp"

int main()
{
    std::vector<std::vector<double>> A = {{5.0, 0.0}, {0.0, 5.0}};
    std::vector<double> b = {0.0, 0.0};

    QuadraticCostFunction cost_func(A, b);
    GradientDescent optimizer(0.01);

    std::vector<double> params = {1.0, 1.0};

    int max_epoch = 20;
    for(int epoch = 0; epoch < max_epoch; epoch++)
    {
        params = optimizer.step(cost_func, params);
        std::cout << "[epoch: " << epoch << "] " 
                << "[cost: " << cost_func.get_cost(params) << "]"
                << std::endl;
    }
}