#include "Day2.h"

#include "RockPaperScissorFight/RockPaperScissorsFight.h"

Day2::Day2() : BaseDay(2) {
}

std::string Day2::DoSolvePart1() const {
    const auto inputFile = OpenInputFile();

    unsigned int sum = 0;

    std::string line;
    while ( std::getline(*inputFile, line) ) {
        RockPaperScissorFight fight(line);
        sum += fight.GetFightScore();
    }

    return std::to_string(sum);
}

std::string Day2::DoSolvePart2() const {
    const auto inputFile = OpenInputFile();

    unsigned int sum = 0;

    std::string line;
    while ( std::getline(*inputFile, line) ) {
        RockPaperScissorFight fight(line, false);
        sum += fight.GetFightScoreImposedChoice();
    }

    return std::to_string(sum);
}

