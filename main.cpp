#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#endif

#include "Day1/Day1.h"
#include "Day2/Day2.h"
#include "Day3/Day3.h"

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    Day1 day1;
    day1.SolveAll();

    Day2 day2;
    day2.SolveAll();

    Day3 day3;
    day3.SolveAll();

    return 0;
}
