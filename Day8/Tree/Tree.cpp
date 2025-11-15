#include "Tree.h"

Tree::Tree(const size_t height, const bool isOnASide) : height(height), isOnASide(isOnASide), highest{0, 0, 0, 0}, viewingDistances{0, 0, 0, 0} {
}

bool Tree::IsVisibleOnAtLeastOnSide() const {
    return isOnASide
        || height > highest[TOP]
        || height > highest[RIGHT]
        || height > highest[BOTTOM]
        || height > highest[LEFT];
}

size_t Tree::GetDirectionHighest(const Direction direction) const {
    return highest[direction];
}

void Tree::SetDirectionHighest(const Direction direction, const size_t size) {
    highest[direction] = size;
}

size_t Tree::GetScenicScore() const {
    size_t sum = 1;
    for (const auto value : viewingDistances) sum *= value;
    return sum;
}

void Tree::IncrementViewingDistance(const Direction direction, const size_t value) {
    viewingDistances[direction] += value;
}

size_t Tree::GetHeight() const {
    return height;
}
