#include "Day3.h"

#include <iostream>
#include <list>

#include "Rucksack/Rucksack.h"

Day3::Day3() : BaseDay(3) {
}

std::string Day3::DoSolvePart1() const {
    const auto inputFile = OpenInputFile();

    unsigned int sum = 0;

    for (std::string line; std::getline(*inputFile, line); ) {
        Rucksack rucksack(line);
        auto duplicateItem = rucksack.GetDuplicateItem();
        if ( duplicateItem!= 0) {
            sum += Rucksack::GetItemPriority(duplicateItem);
        }
    }

    return std::to_string(sum);
}

std::string Day3::DoSolvePart2() const {
    const auto inputFile = OpenInputFile();

    unsigned int sum = 0;

    std::vector<Rucksack> group;
    group.reserve(3);

    for (std::string line; std::getline(*inputFile, line); ) {
        group.emplace_back(line);

        if (group.size() == 3) {
            const auto commonItem = Rucksack::GetCommonItem(group);
            sum += Rucksack::GetItemPriority(commonItem);
            group.clear();
        }
    }

    return std::to_string(sum);
}
