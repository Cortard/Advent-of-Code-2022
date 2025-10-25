#ifndef ADVENT_OF_CODE_2022_DAY3_H
#define ADVENT_OF_CODE_2022_DAY3_H
#include "../BaseDay/BaseDay.h"


class Day3 : public BaseDay {

public:
    Day3();

protected:
    [[nodiscard]] std::string DoSolvePart1() const override;
    [[nodiscard]] std::string DoSolvePart2() const override;
};


#endif //ADVENT_OF_CODE_2022_DAY3_H