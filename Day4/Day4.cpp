#include "Day4.h"

#include <ranges>

Day4::Day4() : BaseDay(4) {
}

std::string Day4::DoSolvePart1() const {
    const auto inputFile = OpenInputFile();

    unsigned int sum = 0;

    for (std::string line; std::getline(*inputFile, line); ) {
        auto sections  = line | std::views::split(',')
                              | std::views::transform([](auto&& section){
                                  std::string s(section.begin(), section.end());
                                  auto dash = s.find('-');
                                  return std::pair{
                                      std::stoi(s.substr(0, dash)),
                                      std::stoi(s.substr(dash+1))
                                  };
                              });

        std::vector ranges(sections.begin(), sections.end());

        if (  ( ranges[0].first <= ranges[1].first && ranges[1].second <= ranges[0].second)
            ||( ranges[1].first <= ranges[0].first && ranges[0].second <= ranges[1].second) ) {
            sum++;
        }
    }

    return std::to_string(sum);
}

std::string Day4::DoSolvePart2() const {
    const auto inputFile = OpenInputFile();

    unsigned int sum = 0;

    for (std::string line; std::getline(*inputFile, line); ) {
        auto sections  = line | std::views::split(',')
                              | std::views::transform([](auto&& section){
                                  std::string s(section.begin(), section.end());
                                  auto dash = s.find('-');
                                  return std::pair{
                                      std::stoi(s.substr(0, dash)),
                                      std::stoi(s.substr(dash+1))
                                  };
                              });

        std::vector ranges(sections.begin(), sections.end());

        if ( ! ( ranges[0].second < ranges[1].first || ranges[1].second < ranges[0].first) ) {
            sum++;
        }
    }

    return std::to_string(sum);
}
