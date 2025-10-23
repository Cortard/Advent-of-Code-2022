#include <format>
#include <stdexcept>

#include "RockPaperScissorsFight.h"

RockPaperScissorFight::RockPaperScissorFight(const std::string &fight) : enemyChoice(None), playerChoice(None), playerImposedResult(Unknow) {
    if (fight.length() < 3) throwConstructionError(fight);

    const char enemyMove = fight.at(0);
    const char playerMove = fight.at(2);
    if (!charToChoice.contains(enemyMove) || !charToChoice.contains(playerMove)) {
        throwConstructionError(fight);
    }

    this->enemyChoice = charToChoice.at(enemyMove);
    this->playerChoice = charToChoice.at(playerMove);
}

RockPaperScissorFight::RockPaperScissorFight(const std::string &fight, bool) : enemyChoice(None), playerChoice(None), playerImposedResult(Unknow)  {
    if (fight.length() < 3) throwConstructionError(fight);

    const char enemyMove = fight.at(0);
    const char playerMove = fight.at(2);
    if (!charToChoice.contains(enemyMove) || !charToChoice.contains(playerMove)) {
        throwConstructionError(fight);
    }

    this->enemyChoice = charToChoice.at(enemyMove);
    this->playerImposedResult = charToResult.at(playerMove);
}

unsigned int RockPaperScissorFight::GetFightScore() const {
    if ( enemyChoice == None ) throw std::runtime_error("Can't calculate fight score because enemyChoice is None");
    if ( playerChoice == None ) throw std::runtime_error("Can't calculate fight score because playerChoice is None");

    unsigned int fightResult;
    if ( (enemyChoice + 1) %3 == playerChoice ) fightResult = 6;
    else if ( enemyChoice == playerChoice ) fightResult = 3;
    else fightResult = 0;

    return fightResult + (playerChoice + 1);
}

unsigned int RockPaperScissorFight::GetFightScoreImposedChoice() {
    if ( enemyChoice == None ) throw std::runtime_error("Can't calculate fight score because enemyChoice is None");
    if ( playerImposedResult == Unknow ) throw std::runtime_error("Can't calculate fight score because playerImposedResult is Unknow");

    switch (playerImposedResult) {
        case Lose:
            playerChoice = ( enemyChoice + 2 ) %3;
            break;
        case Draw:
            playerChoice = enemyChoice;
            break;
        case Win:
            playerChoice = ( enemyChoice + 1 ) %3;
            break;
    }

    return GetFightScore();
}


void RockPaperScissorFight::throwConstructionError(const std::string &fight) {
    throw std::runtime_error(std::format("Error when trying to create aa fight from \"{}\"", fight));
}
