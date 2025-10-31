#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#endif

#include "Day1/Day1.h"
#include "Day2/Day2.h"
#include "Day3/Day3.h"
#include "Day4/Day4.h"
#include "Day5/Day5.h"
#include "Day6/Day6.h"
#include "Day7/Day7.h"

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    std::chrono::high_resolution_clock::duration totalExecutionTime{};

    Day1 day1;
    totalExecutionTime += day1.SolveAll();

    Day2 day2;
    totalExecutionTime += day2.SolveAll();

    Day3 day3;
    totalExecutionTime += day3.SolveAll();

    Day4 day4;
    totalExecutionTime += day4.SolveAll();

    Day5 day5;
    totalExecutionTime += day5.SolveAll();

    Day6 day6;
    totalExecutionTime += day6.SolveAll();

    Day7 day7;
    totalExecutionTime += day7.SolveAll();

    std::cout << std::format("Total time : {}\n", BaseDay::formatDuration(totalExecutionTime));

    return 0;
}
