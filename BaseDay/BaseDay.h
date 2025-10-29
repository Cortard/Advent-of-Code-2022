#ifndef ADVENT_OF_CODE_2022_DAY_TEMPLATE_H
#define ADVENT_OF_CODE_2022_DAY_TEMPLATE_H

#include <chrono>
#include <filesystem>
#include <fstream>
#include <memory>

class BaseDay {

public:
    explicit BaseDay(unsigned int day );
    virtual ~BaseDay() = default;

    std::chrono::high_resolution_clock::duration SolveAll();
    std::chrono::high_resolution_clock::duration SolvePart1();
    std::chrono::high_resolution_clock::duration SolvePart2();

    [[nodiscard]] static std::string formatDuration(std::chrono::high_resolution_clock::duration durationInNano) noexcept;

protected:
    [[nodiscard]] virtual std::string DoSolvePart1() const = 0;
    [[nodiscard]] virtual std::string DoSolvePart2() const = 0;

    [[nodiscard]] std::unique_ptr<std::ifstream> OpenInputFile() const;

private:
    const unsigned int day;

    [[nodiscard]] std::filesystem::path getDataDirectory() const noexcept;

    void printResult(unsigned int part, const std::string& result, std::chrono::steady_clock::duration duration ) const;
    void saveResult(unsigned int part, const std::string& result, std::chrono::steady_clock::duration duration ) const;
    std::chrono::high_resolution_clock::duration solvePart(int part, std::string (BaseDay::*solver)() const) const;
};

#endif //ADVENT_OF_CODE_2022_DAY_TEMPLATE_H