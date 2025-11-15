#ifndef ADVENT_OF_CODE_2022_DAY8_H
#define ADVENT_OF_CODE_2022_DAY8_H
#include <iosfwd>
#include <vector>

#include "../BaseDay/BaseDay.h"
#include "Tree/Tree.h"


class Day8 final : public BaseDay {

public:
    Day8();

protected:
    [[nodiscard]] std::string DoSolvePart1() const override;
    [[nodiscard]] std::string DoSolvePart2() const override;

private:
    static void ExtractForest(const std::unique_ptr<std::ifstream> &inputFile, std::vector<std::vector<Tree>> &forest);

    static void FillHighestByLineAndColumn(std::vector<std::vector<Tree>> &forest);
    static void FillTopAndLeftHighest(std::vector<std::vector<Tree>> &forest);
    static void FillBottomAndRightHighest(std::vector<std::vector<Tree>> &forest);

    static void FillViewingDistance(std::vector<std::vector<Tree>> &forest, size_t maxHeight);

};


#endif //ADVENT_OF_CODE_2022_DAY8_H