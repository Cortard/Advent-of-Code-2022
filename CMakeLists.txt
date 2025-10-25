cmake_minimum_required(VERSION 4.0)
project(Advent_of_Code_2022)

set(CMAKE_CXX_STANDARD 20)

add_executable(Advent_of_Code_2022 main.cpp
        BaseDay/BaseDay.h
        BaseDay/BaseDay.cpp
        Day1/Day1.h
        Day1/Day1.cpp
        Day2/Day2.h
        Day2/Day2.cpp
        Day2/RockPaperScissorFight/RockPaperScissorsFight.h
        Day2/RockPaperScissorFight/RockPaperScissorFight.cpp
        Day3/Day3.h
        Day3/Day3.cpp
        Day3/Rucksack/Rucksack.h
        Day3/Rucksack/Rucksack.cpp
)
