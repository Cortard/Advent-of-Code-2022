#ifndef ADVENT_OF_CODE_2022_DAY1_H
#define ADVENT_OF_CODE_2022_DAY1_H

#include "../BaseDay/BaseDay.h"

class Day1 final : public BaseDay {

public:
    Day1();

protected:
    [[nodiscard]] std::string DoSolvePart1() const override;
    [[nodiscard]] std::string DoSolvePart2() const override;

private:
    static void UpdateMaxValue(unsigned int& currentMaxValue, unsigned int newPotentialValue);
    static void UpdateTopThreeMaxValue(unsigned int currentMaxValues[3], unsigned int newPotentialValue);
};


#endif //ADVENT_OF_CODE_2022_DAY1_H