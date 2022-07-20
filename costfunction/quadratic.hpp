#pragma once

#include <vector>
#include "base.hpp"

class QuadraticCostFunction : public BaseCostFunction
{
    /*
        2次形式のコスト関数のクラス
        cost(x) = x^T * A * x + b^T * x
    */
public:
    std::vector<std::vector<double>> A;
    std::vector<double> b;
    int n;

    QuadraticCostFunction(
        const std::vector<std::vector<double>>& A,
        const std::vector<double>& b
    );
    double get_cost(const std::vector<double>& params) const override;
    std::vector<double> get_grad(const std::vector<double>& params) const override;
};

