#include <vector>

#include "../costfunction/base.hpp"
#include "gradient_descent.hpp"

GradientDescent::GradientDescent(double lr)
    : lr(lr)
{
};

std::vector<double> GradientDescent::step(
    const BaseCostFunction& cost_func,
    const std::vector<double>& params
) const
{
    int n = params.size();
    std::vector<double> grad = cost_func.get_grad(params);
    std::vector<double> new_params(n);

    for(int i = 0; i < n; i++)
    {
        new_params[i] = params[i] - lr * grad[i];
    }

    return new_params;
}
