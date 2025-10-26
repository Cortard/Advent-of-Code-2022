#ifndef ADVENT_OF_CODE_2022_DAY5_H
#define ADVENT_OF_CODE_2022_DAY5_H

#include <functional>
#include <stack>

#include "../BaseDay/BaseDay.h"


class Day5 final : public BaseDay {

public:
    Day5();

protected:
    [[nodiscard]] std::string DoSolvePart1() const override;
    [[nodiscard]] std::string DoSolvePart2() const override;

private:
    enum ReadingStep {
        LoadingStacksCrates,
        WaitingForMoveInstruction,
        MovingCrates
    };

    static std::vector<std::stack<char>> GetInitialStacks(std::ifstream &file);

    static bool IsEndOfStacksDescription(const std::string& line);
    static void SetUpStackVector(size_t size, std::vector<std::stack<char>> &stacks);
    static void CopyCratesInStacks(const std::string &line, std::vector<std::stack<char>> &stacks);

    static void ExecuteMoveOnStacks(
        std::ifstream &file,
        std::vector<std::stack<char>> &stacks,
        const std::function<void(unsigned int number, std::stack<char>& source, std::stack<char>& destination)>& crateMover
    );

    static std::array<unsigned int, 3> GetInstructions(const std::string& line);
    static void MoveCrates(
        std::vector<std::stack<char>> &stacks,
        const std::array<unsigned int, 3> &instructions,
        const std::function<void(unsigned int number, std::stack<char>& source, std::stack<char>& destination)>& crateMover
    );

    static void CratesMover9000(unsigned int number, std::stack<char> &source, std::stack<char> &destination);
    static void CratesMover9001(unsigned int number, std::stack<char> &source, std::stack<char> &destination);
};


#endif //ADVENT_OF_CODE_2022_DAY5_H