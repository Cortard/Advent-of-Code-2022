#ifndef ADVENT_OF_CODE_2022_DAY0_H
#define ADVENT_OF_CODE_2022_DAY0_H
#include <queue>

#include "../BaseDay/BaseDay.h"


class Day6 final : public BaseDay {

public:
    Day6();

protected:
    [[nodiscard]] std::string DoSolvePart1() const override;
    [[nodiscard]] std::string DoSolvePart2() const override;

private:
    static size_t FindFirstAllDistinctSubstringEndIndex(std::ifstream &file, size_t bufferMaxSize);
    static size_t GetMinimalDistanceToPotentialValidPosition(const std::deque<char> &buffer, size_t bufferMaxSize);
    static bool MoveBufferForwards(std::deque<char> &buffer, std::ifstream &file, size_t distance, size_t bufferMaxSize);
    static void AddToQueue(char item, std::deque<char> &queue, size_t queueMaxSize);
};


#endif //ADVENT_OF_CODE_2022_DAY0_H