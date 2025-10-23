#ifndef ADVENT_OF_CODE_2022_ROCKPAPERSCISSORSFIGHT_H
#define ADVENT_OF_CODE_2022_ROCKPAPERSCISSORSFIGHT_H

#include <string>
#include <unordered_map>

class RockPaperScissorFight {

public:
    explicit RockPaperScissorFight(const std::string &fight);
    explicit RockPaperScissorFight(const std::string &fight, bool);

    unsigned int GetFightScore() const;
    unsigned int GetFightScoreImposedChoice();

private :
    enum FightChoice { Rock = 0, Paper = 1, Scissor = 2, None = -1 };
    static inline const std::unordered_map<char, FightChoice> charToChoice = {
        {'A', Rock},
        {'B', Paper},
        {'C', Scissor},
        {'X', Rock},
        {'Y', Paper},
        {'Z', Scissor}
    };

    enum FightResult { Lose = 0, Draw = 1, Win = 2, Unknow = -1 };
    static inline const std::unordered_map<char, FightResult> charToResult = {
        {'X', Lose},
        {'Y', Draw},
        {'Z', Win}
    };

    FightChoice enemyChoice;
    int playerChoice;

    FightResult playerImposedResult;

    static void throwConstructionError(const std::string &fight);
};

#endif //ADVENT_OF_CODE_2022_ROCKPAPERSCISSORSFIGHT_H