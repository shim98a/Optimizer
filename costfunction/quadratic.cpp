#include <vector>

#include "quadratic.hpp"

QuadraticCostFunction::QuadraticCostFunction(
    const std::vector<std::vector<double>>& A,
    const std::vector<double>& b
) : A(A), b(b), n(b.size())
{
    if(A.size() != b.size())
    {
        throw "Matrix size of A is NOT consistent with the vector size of b";
    }
    // 本来はAの対称性のチェックも必要だがめんどいので省略
};

double QuadraticCostFunction::get_cost(
    const std::vector<double>& params
) const
{
    if(params.size() != b.size())
    {
        throw "Inconsistent vector sizes !!";
    }

    double cost = 0.0;

    for(int i = 0; i < n; i++)
    {
        cost = cost + b[i] * params[i];
        for(int j = 0; j < n; j++)
        {
            cost = cost + params[i] * A[i][j] * params[j];
        }
    }

    return cost;
};

std::vector<double> QuadraticCostFunction::get_grad(
    const std::vector<double>& params
) const
{
    if(params.size() != b.size())
    {
        throw "Inconsistent vector sizes !!";
    }

    std::vector<double> grad(n);
    for(int i = 0; i < n; i++)
    {
        grad[i] = grad[i] + b[i];
        for(int j = 0; j < n; j++)
        {
            grad[i] = grad[i] + 0.5 * A[i][j] * params[j];
        }
    }

    return grad;
}
