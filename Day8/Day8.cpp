#include "Day8.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>

#include "Tree/Tree.h"

Day8::Day8() : BaseDay(8) {
}

std::string Day8::DoSolvePart1() const { //1779
    const auto inputFile = OpenInputFile();

    std::vector<std::vector<Tree>> forest;
    ExtractForest(inputFile, forest);
    FillHighestByLineAndColumn(forest);

    size_t count = std::ranges::count_if( forest | std::views::join, &Tree::IsVisibleOnAtLeastOnSide);

    return std::to_string(count);
}

std::string Day8::DoSolvePart2() const {
    const auto inputFile = OpenInputFile();

    std::vector<std::vector<Tree>> forest;
    ExtractForest(inputFile, forest);
    FillViewingDistance(forest, 10);

    const size_t result = std::ranges::max(forest | std::views::join, {}, &Tree::GetScenicScore).GetScenicScore();

    return std::to_string(result);
}

void Day8::ExtractForest(const std::unique_ptr<std::ifstream> &inputFile, std::vector<std::vector<Tree>> &forest) {
    size_t lineIndex = 0;
    for (std::string line; std::getline(*inputFile, line); lineIndex++) {
        forest.emplace_back();

        for (size_t i=0; i<line.size(); i++) {
            const size_t height = line.at(i) - '0';
            const bool isOnASide = lineIndex==0 || lineIndex==line.size()-1 || i==0 || i==line.size()-1;
            Tree tree(height, isOnASide);
            forest[lineIndex].push_back(tree);
        }
    }
}

void Day8::FillHighestByLineAndColumn(std::vector<std::vector<Tree>> &forest) {
    FillTopAndLeftHighest(forest);
    FillBottomAndRightHighest(forest);
}

void Day8::FillTopAndLeftHighest(std::vector<std::vector<Tree>> &forest) {
    for (size_t lineIndex = 0; lineIndex < forest.size(); lineIndex++) {
        size_t highestOnLine = 0;
        for ( size_t i=0; i<forest[0].size(); i++ ) {
            auto& tree = forest[lineIndex][i];
            tree.SetDirectionHighest(LEFT, highestOnLine);
            highestOnLine = std::max(highestOnLine, tree.GetHeight());
            if (lineIndex!=0) {
                const auto lastTree = forest[lineIndex - 1][i];
                const auto highestOnColumn = std::max(lastTree.GetHeight(), lastTree.GetDirectionHighest(TOP));
                tree.SetDirectionHighest(TOP, highestOnColumn);
            } else tree.SetDirectionHighest(TOP, 0);
        }
    }
}

void Day8::FillBottomAndRightHighest(std::vector<std::vector<Tree>> &forest) {
    for (size_t lineIndex = forest.size(); lineIndex != 0; lineIndex--) {
        size_t highestOnLine = 0;
        for ( size_t i=forest[0].size(); i!=0; i-- ) {
            auto& tree = forest[lineIndex-1][i-1];
            tree.SetDirectionHighest(RIGHT, highestOnLine);
            highestOnLine = std::max(highestOnLine, tree.GetHeight());
            if (lineIndex!=forest.size()) {
                const auto lastTree = forest[lineIndex][i-1];
                const auto highestOnColumn = std::max(lastTree.GetHeight(), lastTree.GetDirectionHighest(BOTTOM));
                tree.SetDirectionHighest(BOTTOM, highestOnColumn);
            } else tree.SetDirectionHighest(BOTTOM, 0);
        }
    }
}

void Day8::FillViewingDistance(std::vector<std::vector<Tree>> &forest, const size_t maxHeight) {
    Tree* viewingTreeByColumn[forest[0].size()][maxHeight];
    for (auto i = 0; i< forest[0].size(); i++) for (auto j = 0; j< maxHeight; j++) viewingTreeByColumn[i][j] = nullptr;

    for (auto & treeLine : forest) {
        Tree* viewingTree[maxHeight];
        for (auto i = 0; i< maxHeight; i++) viewingTree[i] = nullptr;

        int index = 0;
        for ( auto& tree : treeLine ) {
            for (const auto otherTree : viewingTree) if (otherTree) otherTree->IncrementViewingDistance(RIGHT, 1);
            for (auto i=0; i<=tree.GetHeight(); i++) viewingTree[i] = nullptr;
            viewingTree[tree.GetHeight()] = &tree;

            for (const auto otherTree : viewingTreeByColumn[index]) if (otherTree) otherTree->IncrementViewingDistance(TOP, 1);
            for (auto i=0; i<=tree.GetHeight(); i++) viewingTreeByColumn[index][i] = nullptr;
            viewingTreeByColumn[index][tree.GetHeight()] = &tree;
            index++;
        }
    }

    for (auto i = 0; i< forest.size(); i++) for (auto j = 0; j< maxHeight; j++) viewingTreeByColumn[i][j] = nullptr;

    for (auto & treeLine : std::ranges::reverse_view(forest)) {
        Tree* viewingTree[maxHeight];
        for (auto i = 0; i< maxHeight; i++) viewingTree[i] = nullptr;

        int index = 0;
        for ( auto& tree : std::ranges::reverse_view(treeLine) ) {
            for (const auto otherTree : viewingTree) if (otherTree) otherTree->IncrementViewingDistance(LEFT, 1);
            for (auto i=0; i<=tree.GetHeight(); i++) viewingTree[i] = nullptr;
            viewingTree[tree.GetHeight()] = &tree;

            for (const auto otherTree : viewingTreeByColumn[index]) if (otherTree) otherTree->IncrementViewingDistance(BOTTOM, 1);
            for (auto i=0; i<=tree.GetHeight(); i++) viewingTreeByColumn[index][i] = nullptr;
            viewingTreeByColumn[index][tree.GetHeight()] = &tree;
            index++;
        }
    }
}