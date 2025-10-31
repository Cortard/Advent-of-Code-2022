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
        Day4/Day4.h
        Day4/Day4.cpp
        Day5/Day5.h
        Day5/Day5.cpp
        Day6/Day6.h
        Day6/Day6.cpp
        Day7/Day7.h
        Day7/Day7.cpp
        Day7/FileSystemNode/FileSystemNode.h
        Day7/FileSystemNode/FileSystemNode.cpp
        Day7/Directory/Directory.h
        Day7/Directory/Directory.cpp
        Day7/File/File.h
        Day7/File/File.cpp
)
