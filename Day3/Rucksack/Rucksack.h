#ifndef ADVENT_OF_CODE_2022_RUCKSACK_H
#define ADVENT_OF_CODE_2022_RUCKSACK_H

#include <set>
#include <string>
#include <vector>

class Rucksack {

public:
    explicit Rucksack(const std::string& rucksack);
    [[nodiscard]] char GetDuplicateItem() const;

    [[nodiscard]] std::size_t Size() const;
    [[nodiscard]] bool Contains(char item) const;

    static int GetItemPriority(char item);
    static char GetCommonItem(const std::vector<Rucksack> & rucksacks);

private:
    std::set<char> compartments[2];

};


#endif //ADVENT_OF_CODE_2022_RUCKSACK_H