#include <iostream>
#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main()
{
    auto data = std::make_shared<const InputData>(InputData{0.8, 1.0, 0.1, 10});
    auto resultB = calculateB(data);
    auto [valueB, exactB, errorB, itB, nameB] = *resultB;
    std::cout << nameB << ": y = " << valueB << std::endl;
    return 0;
}