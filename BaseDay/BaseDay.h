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

    void SolveAll();
    void SolvePart1();
    void SolvePart2();

protected:
    [[nodiscard]] virtual std::string DoSolvePart1() const = 0;
    [[nodiscard]] virtual std::string DoSolvePart2() const = 0;

    [[nodiscard]] std::unique_ptr<std::ifstream> OpenInputFile() const;

private:
    const unsigned int day;

    [[nodiscard]] static std::string formatDuration(std::chrono::high_resolution_clock::duration durationInNano) noexcept;
    [[nodiscard]] std::filesystem::path getDataDirectory() const noexcept;

    void saveResult(unsigned int part, const std::string& result, std::chrono::steady_clock::duration duration ) const;
    void solvePart(int part, std::string (BaseDay::*solver)() const) const;
};

#endif //ADVENT_OF_CODE_2022_DAY_TEMPLATE_H