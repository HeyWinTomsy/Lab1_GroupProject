#pragma once

#include <vector>
#include <string>

struct InputData
{
    double x0;
    double y0;
    double h;
    int steps;
};

struct Result
{
    std::vector<double> xValues;
    std::vector<double> yValues;

    double finalValue;
    double exactValue;
    double error;

    int iterations;
    double executionTimeMs;

    std::string methodName;
};