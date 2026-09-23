#include <memory>
#include <cmath>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);

// Рівняння поки що жорстко задане тут, а не в даних.
static double f(double x, double y)
{
    return y / x;
}

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data)
{
    double x = data->x0;
    double y = data->y0;
    const double h = data->h;

    int steps = 0;
    for (int i = 0; i < data->steps; ++i)
    {
        y = y + h * f(x, y);
        x = x + h;
        ++steps;
    }

    const double C = data->y0 / data->x0;
    const double exact = C * x;

    auto result = std::make_unique<Result>();
    result->value = y;
    result->exactValue = exact;
    result->error = std::fabs(y - exact);
    result->iterations = steps;
    result->methodName = "Euler method (Student A)";
    return result;
}