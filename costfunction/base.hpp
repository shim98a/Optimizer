#pragma once

#include <vector>

class BaseCostFunction
{
public:
    virtual double get_cost(const std::vector<double>& params) const = 0;
    virtual std::vector<double> get_grad(const std::vector<double>& params) const = 0;
};