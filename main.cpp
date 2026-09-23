#include <iostream>
#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);

int main()
{
    auto data = std::make_shared<const InputData>(InputData{0.8, 1.0, 0.1, 10});
    auto resultA = calculateA(data);          // <-- виклик Студента А
    auto [valueA, exactA, errorA, itA, nameA] = *resultA;
    std::cout << nameA << ": y = " << valueA << std::endl;
    return 0;
}