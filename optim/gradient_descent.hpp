#pragma once

#include <vector>
#include "../costfunction/base.hpp"

class GradientDescent
{
    /*
        ただの再急降下法. 更新則は
        x <- x - lr * grad(x)
    */
public:
    double lr; // learning rate

    GradientDescent(double lr);

    virtual std::vector<double> step(
        const BaseCostFunction& cost_func,
        const std::vector<double>& params
    ) const;
};
