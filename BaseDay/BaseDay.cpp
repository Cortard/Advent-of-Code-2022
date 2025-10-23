#include "BaseDay.h"

#include <filesystem>
#include <memory>
#include <iostream>

void BaseDay::SolveAll() {
    try { SolvePart1(); }
    catch (const std::exception& e) {
        std::cerr << std::format("Day {} Part1 failed: ", day) << e.what() << '\n';
    }

    try { SolvePart2(); }
    catch (const std::exception& e) {
        std::cerr << std::format("Day {} Part2 failed: ", day) << e.what() << '\n';
    }
}

void BaseDay::SolvePart1() {
    solvePart(1, &BaseDay::DoSolvePart1);
}

void BaseDay::SolvePart2() {
    solvePart(2, &BaseDay::DoSolvePart2);
}

std::unique_ptr<std::ifstream> BaseDay::OpenInputFile() const {
    const auto inputFile = getDataDirectory() / "input.txt";
    auto file = std::make_unique<std::ifstream>(inputFile);
    if (!file->is_open()) {
        throw std::runtime_error(std::format("Error opening file at {}", inputFile.string()));
    }
    return file;
}

void BaseDay::solvePart(const int part, std::string (BaseDay::*solver)() const) const {
    const auto start = std::chrono::steady_clock::now();
    const std::string result = (this->*solver)();
    const auto end = std::chrono::steady_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    printResult(part, result, duration);
    saveResult(part, result, duration);
}

void BaseDay::printResult(unsigned int part, const std::string &result, const std::chrono::steady_clock::duration duration) const {
    std::cout << std::format("Result for Day {} Part {} in {} : {}\n", day, part, formatDuration(duration), result);
}

void BaseDay::saveResult(unsigned int part, const std::string& result, const std::chrono::nanoseconds duration) const {
    const auto outputFile = getDataDirectory() / std::format("Day{}-Part{}.txt", day, part);
    std::ofstream file(outputFile);
    if (!file.is_open()) {
        throw std::runtime_error(std::format("Error opening file at {}", outputFile.string()));
    }

    file << std::format("Result for Day {} Part {}:\n", day, part);
    file << std::format("\tResult value: {}\n", result);
    file << std::format("\tTotal execution time: {}\n", formatDuration(duration));
}

std::filesystem::path BaseDay::getDataDirectory() const noexcept{
    const std::filesystem::path currentFile(__FILE__);
    const std::filesystem::path sourceDir = currentFile.parent_path();
    const std::filesystem::path rootDir = sourceDir.parent_path();
    const std::filesystem::path dataDir = rootDir / std::format("Day{}", day);
    return dataDir;
}

std::string BaseDay::formatDuration(const std::chrono::nanoseconds durationInNano) noexcept {
    using namespace std::chrono;

    if (durationInNano >= 60s) {
        double minutes = duration_cast<duration<double, std::ratio<60>>>(durationInNano).count();
        return std::format("{:.3f} min", minutes);
    }
    if (durationInNano >= 1s) {
        double seconds = duration_cast<duration<double>>(durationInNano).count();
        return std::format("{:.3f} s", seconds);
    }
    if (durationInNano >= 1ms) {
        double millis = duration_cast<duration<double, std::milli>>(durationInNano).count();
        return std::format("{:.3f} ms", millis);
    }
    if (durationInNano >= 1us) {
        double micros = duration_cast<duration<double, std::micro>>(durationInNano).count();
        return std::format("{:.3f} µs", micros);
    }
    double nanos = duration_cast<duration<double, std::nano>>(durationInNano).count();
    return std::format("{:.3f} ns", nanos);
}


BaseDay::BaseDay(const unsigned int day) : day(day) {}