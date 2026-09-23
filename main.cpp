#include <iostream>
#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);

int main()
{
    auto data = std::make_shared<const InputData>(InputData{0.8, 1.0, 0.1, 10});
    auto resultB = calculateB(data);
    auto [valueB, exactB, errorB, itB, nameB] = *resultB;
    auto resultA = calculateA(data);
    auto [valueA, exactA, errorA, itA, nameA] = *resultA;
    std::cout << nameB << ": y = " << valueB << std::endl;
    std::cout << nameA << ": y = " << valueA << std::endl;
    return 0;
}