#include <iostream>
#include <iomanip>
#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

void printTable(const Result& r){
    std::cout << "\n" << r.methodName << "\n";
    std::cout << "----------------------------\n";
    std::cout << "i\t x\t\t y\n";
    for (size_t i = 0; i < r.xValues.size(); ++i){
        std::cout << i << "\t"
                  << r.xValues[i] << "\t"
                  << r.yValues[i] << "\n";
    }
    std::cout << "\nFinal value: "<< r.finalValue << "\n";
    std::cout << "Exact value: "<< r.exactValue << "\n";
    std::cout << "Error: "<< r.error << "\n";
    std::cout << "Iterations: "<< r.iterations << "\n";
    std::cout << "Time: "<< r.executionTimeMs<< " ms\n";
}

int main()
{
    auto data =std::make_shared<const InputData>(
            InputData{
                0.8,
                1.0,
                0.01,
                100
            });
    auto resultA = calculateA(data);
    auto resultB = calculateB(data);

    auto [xA, yA, finalA, exactA,errorA, iterA, timeA, nameA] = *resultA;
    auto [xB, yB, finalB, exactB,errorB, iterB, timeB, nameB] = *resultB;

    std::cout << std::fixed << std::setprecision(6);

    printTable(*resultA);
    printTable(*resultB);

    std::cout << "\nCOMPARISON\n";
    std::cout << "\nAccuracy:\n";

    if (errorA < errorB)
        std::cout << nameA << " is more accurate\n";
    else
        std::cout << nameB << " is more accurate\n";

    std::cout << "\nExecution time:\n";

    if (timeA < timeB)
        std::cout << nameA << " is faster\n";
    else
        std::cout << nameB << " is faster\n";

    return 0;
}