#include <memory>
#include <cmath>
#include <chrono>

#include "shared_types.h"

static double f(double x, double y)
{
    return y / x;
}

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data){
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
        double k1 = f(x, y);
        double k2 = f(x + h / 2.0, y + h * k1 / 2.0);
        double k3 = f(x + h / 2.0, y + h * k2 / 2.0);
        double k4 = f(x + h, y + h * k3);

        y = y + h * (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x += h;

        result->xValues.push_back(x);
        result->yValues.push_back(y);

        ++steps;
    }

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

    result->methodName = "Runge-Kutta 4";

    return result;
}