#include "Day1.h"

#include <iostream>

Day1::Day1() : BaseDay(1) {
}

std::string Day1::DoSolvePart1() const {
    const auto inputFile = OpenInputFile();

    unsigned int maxCalories = 0;
    unsigned int currentCaloriesSum = 0;

    std::string line;
    while ( std::getline(*inputFile, line) ) {

        if ( line.empty() ) {
            UpdateMaxValue(maxCalories, currentCaloriesSum);
            currentCaloriesSum = 0;
        } else {
            currentCaloriesSum += std::stoi(line);
        }
    }

    UpdateMaxValue(maxCalories, currentCaloriesSum);

    return std::to_string(maxCalories);
}

std::string Day1::DoSolvePart2() const {
    const auto inputFile = OpenInputFile();

    unsigned int maxCalories[3] = {0, 0, 0};
    unsigned int currentCaloriesSum = 0;

    std::string line;
    while ( std::getline(*inputFile, line) ) {

        if ( line.empty() ) {
            UpdateTopThreeMaxValue(maxCalories, currentCaloriesSum);
            currentCaloriesSum = 0;
        } else {
            currentCaloriesSum += std::stoi(line);
        }
    }

    UpdateTopThreeMaxValue(maxCalories, currentCaloriesSum);
    unsigned int sum = 0;
    for (unsigned int i = 0; i < 3; ++i) {
        sum += maxCalories[i];
    }

    return std::to_string(sum);
}

void Day1::UpdateMaxValue(unsigned int& currentMaxValue, const unsigned int newPotentialValue) {
    if ( newPotentialValue > currentMaxValue ) {
        currentMaxValue = newPotentialValue;
    }
}

void Day1::UpdateTopThreeMaxValue(unsigned int currentMaxValues[3], const unsigned int newPotentialValue) {
    for (int i = 0; i < 3; ++i) {
        if (newPotentialValue > currentMaxValues[i]) {
            for (int j = 2; j > i; --j) {
                currentMaxValues[j] = currentMaxValues[j-1];
            }
            currentMaxValues[i] = newPotentialValue;
            return;
        }
    }
}