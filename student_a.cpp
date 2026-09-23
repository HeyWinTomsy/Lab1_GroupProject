#include <memory>
#include <cmath>
#include <chrono>

#include "shared_types.h"

static double f(double x, double y)
{
    return y / x;
}

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data){
    auto start = std::chrono::high_resolution_clock::now();

    double x = data->x0;
    double y = data->y0;
    double h = data->h;

    auto result = std::make_unique<Result>();

    result->xValues.push_back(x);
    result->yValues.push_back(y);

    int steps = 0;

    for (int i = 0; i < data->steps; ++i)
    {
        y = y + h * f(x, y);
        x = x + h;

        result->xValues.push_back(x);
        result->yValues.push_back(y);

        ++steps;
    }

    // Точний розв'язок
    double C = data->y0 / data->x0;
    double exact = C * x;

    auto end = std::chrono::high_resolution_clock::now();

    result->finalValue = y;
    result->exactValue = exact;
    result->error = std::fabs(y - exact);
    result->iterations = steps;

    result->executionTimeMs =
        std::chrono::duration<double, std::milli>(
            end - start).count();

    result->methodName = "Euler Method";

    return result;
}