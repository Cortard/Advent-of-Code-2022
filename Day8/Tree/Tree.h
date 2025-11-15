#ifndef ADVENT_OF_CODE_2022_TREE_H
#define ADVENT_OF_CODE_2022_TREE_H

#include <unordered_map>
#include <vector>

enum Direction {
    TOP = 0,
    RIGHT = 1,
    BOTTOM = 2,
    LEFT = 3
};

class Tree {

public:
    explicit Tree(size_t height, bool isOnASide);

    [[nodiscard]] bool IsVisibleOnAtLeastOnSide() const;

    [[nodiscard]] size_t GetDirectionHighest(Direction direction) const;
    void SetDirectionHighest(Direction direction, size_t size);

    [[nodiscard]] size_t GetScenicScore() const;
    void IncrementViewingDistance(Direction direction, size_t value);

    [[nodiscard]] size_t GetHeight() const;

private :
    size_t height;
    bool isOnASide;

    size_t highest[4];

    size_t viewingDistances[4];
};


#endif //ADVENT_OF_CODE_2022_TREE_H