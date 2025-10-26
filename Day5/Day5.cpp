#include "Day5.h"

#include <iostream>
#include <ranges>
#include <regex>
#include <stack>

Day5::Day5() : BaseDay(5) {
}

std::string Day5::DoSolvePart1() const {
    const auto inputFile = OpenInputFile();

    auto stacks = GetInitialStacks(*inputFile);

    ExecuteMoveOnStacks(*inputFile, stacks, Day5::CratesMover9000);

    std::string result;
    for ( auto& stack : stacks ) {
        result += stack.top();
    }

    return result;
}

std::string Day5::DoSolvePart2() const {
    const auto inputFile = OpenInputFile();

    auto stacks = GetInitialStacks(*inputFile);

    ExecuteMoveOnStacks(*inputFile, stacks, Day5::CratesMover9001);

    std::string result;
    for ( auto& stack : stacks ) {
        result += stack.top();
    }

    return result;
}

std::vector<std::stack<char>> Day5::GetInitialStacks(std::ifstream &file) {
    std::string line;
    std::vector<std::string> stacksDescription;

    while ( std::getline(file, line) ) {
        if ( ! IsEndOfStacksDescription(line) ) {
            stacksDescription.push_back(line);
        } else break;
    }

    std::vector<std::stack<char>> stacks;
    const auto numberOfStack = line.length() / 4 + 1;
    SetUpStackVector(numberOfStack, stacks);
    for ( size_t i=stacksDescription.size(); i!=0; i-- ) {
        CopyCratesInStacks(stacksDescription.at(i-1), stacks);
    }

    return stacks;
}

bool Day5::IsEndOfStacksDescription(const std::string &line) {
    return line.length() < 2 || line.at(1) == '1';
}

void Day5::SetUpStackVector(const size_t size, std::vector<std::stack<char>>& stacks) {
    stacks.reserve(size);
    for (int i = 0; i<size; i++) stacks.emplace_back();
}

std::array<unsigned int, 3> Day5::GetInstructions(const std::string& line) {
    const std::regex regex(R"(\d+)");
    std::sregex_iterator it(line.begin(), line.end(), regex);

    auto i = 0;
    std::array<unsigned int, 3> numbers{};
    for (const std::sregex_iterator end; it != end && i < 3; ++it) {
        numbers[i++] = std::stoi(it->str());
    }

    return numbers;
}

void Day5::CopyCratesInStacks(const std::string &line, std::vector<std::stack<char> > &stacks) {
    for (int i=1; i<line.length(); i+=4) {
        auto crate = line.at(i);
        if ( crate != ' ' ) {
            stacks.at( (i-1) / 4 ).push(crate);
        }
    }
}

void Day5::ExecuteMoveOnStacks(
    std::ifstream &file,
    std::vector<std::stack<char>> &stacks,
    const std::function<void(unsigned int number, std::stack<char>& source, std::stack<char>& destination)>& crateMover
) {
    std::string line;
    while ( std::getline(file, line) && line.empty() ) {}

    do {
        auto instructions = GetInstructions(line);
        MoveCrates(stacks, instructions, crateMover);
    } while ( std::getline(file, line) );
}

void Day5::MoveCrates(
    std::vector<std::stack<char>> &stacks,
    const std::array<unsigned int, 3> &instructions,
    const std::function<void(unsigned int number, std::stack<char>& source, std::stack<char>& destination)>& crateMover
) {
    const auto number = instructions.at(0);
    const auto source = instructions.at(1) - 1 ;
    const auto destination = instructions.at(2) - 1;
    auto& sourceCrate = stacks.at(source);
    auto& destinationCrate = stacks.at(destination);
    crateMover(number, sourceCrate, destinationCrate);
}

void Day5::CratesMover9000(const unsigned int number, std::stack<char>& source, std::stack<char>& destination) {
    for ( int i=0; i<number; i++ ) {
        const auto item =  source.top();
        destination.push(item);
        source.pop();
    }
}

void Day5::CratesMover9001(const unsigned int number, std::stack<char>& source, std::stack<char>& destination) {
    std::stack<char> temp;
    for ( int i=0; i<number; i++ ) {
        const auto item =  source.top();
        temp.push(item);
        source.pop();
    }
    for ( int i=0; i<number; i++ ) {
        const auto item =  temp.top();
        destination.push(item);
        temp.pop();
    }
}