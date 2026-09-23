#include <memory>
#include <cmath>
#include "shared_types.h"

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

static double f(double x, double y)
{
    return y / x;
}

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data)
{
    double x = data->x0;
    double y = data->y0;
    const double h = data->h;

    int steps = 0;
    for (int i = 0; i < data->steps; ++i)
    {
        const double k1 = f(x, y);
        const double k2 = f(x + h / 2, y + h / 2 * k1);
        const double k3 = f(x + h / 2, y + h / 2 * k2);
        const double k4 = f(x + h, y + h * k3);
        y = y + (h / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
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
    result->methodName = "Runge-Kutta 4th order method (Student B)";
    return result;
}
