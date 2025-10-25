#include "Rucksack.h"

#include <algorithm>
#include <format>
#include <ranges>
#include <stdexcept>
#include <vector>

Rucksack::Rucksack(const std::string &rucksack) : compartments { std::set<char>(), std::set<char>() } {
    const auto length = rucksack.length();
    for ( int i=0; i<length; i++ ) {
        char item = rucksack[i];
        auto& compartment = compartments[ i < length/2 ];

        if ( !compartment.contains(item) ) compartment.insert(item);
    }
}

char Rucksack::GetDuplicateItem() const {
    for ( auto item : compartments[0]) {
        if ( compartments[1].contains(item) ) return item;
    }
    return 0;
}

std::size_t Rucksack::Size() const {
    return compartments[0].size();
}

bool Rucksack::Contains(const char item) const {
    return std::ranges::any_of(compartments, [&](const auto& compartment) {
        return compartment.contains(item);
    });
}

int Rucksack::GetItemPriority(char item) {
    if ( 'a' <= item  && item <= 'z' ) return item - 'a' + 1;
    if ( 'A' <= item  && item <= 'Z' ) return item - 'A' + 1 + 26;
    throw std::runtime_error(std::format("Invalid item '{}' ({})", item, static_cast<int>(item)));
}

char Rucksack::GetCommonItem(const std::vector<Rucksack> &rucksacks) {
    const auto bySize = [](const auto& e) { return e.Size(); };
    auto shortest_it = std::ranges::min_element(rucksacks, {}, bySize);
    if (shortest_it == rucksacks.cend()) return {};

    for (const auto item : shortest_it->compartments | std::views::join) {
        if (std::ranges::all_of(rucksacks, [&](const auto& rucksack) {
            return &rucksack == &*shortest_it || rucksack.Contains(item);
        }))
            return item;
    }

    return 0;
}
