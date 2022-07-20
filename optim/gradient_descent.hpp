#pragma once

#include <vector>
#include "../costfunction/base.hpp"

class GradientDescent
{
public:
    double lr; // learning rate

    GradientDescent(double lr);

    virtual std::vector<double> step(
        const BaseCostFunction& cost_func,
        const std::vector<double>& params
    ) const;
};
