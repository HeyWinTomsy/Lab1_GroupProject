#pragma once
#include <string>

struct InputData
{
    double x0;
    double y0;
    double h;
    int    steps;
};

struct Result
{
    double value;
    double exactValue;
    double error;
    int    iterations;
    std::string methodName;
};