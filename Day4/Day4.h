#ifndef ADVENT_OF_CODE_2022_DAY4_H
#define ADVENT_OF_CODE_2022_DAY4_H
#include "../BaseDay/BaseDay.h"


class Day4 : public BaseDay {

public:
    Day4();

protected:
    [[nodiscard]] std::string DoSolvePart1() const override;
    [[nodiscard]] std::string DoSolvePart2() const override;
};

#endif //ADVENT_OF_CODE_2022_DAY4_H