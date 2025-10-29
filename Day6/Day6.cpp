#include "Day6.h"

#include <deque>

Day6::Day6() : BaseDay(6) {
}

std::string Day6::DoSolvePart1() const {
    const auto inputFile = OpenInputFile();

    constexpr size_t bufferMaxSize = 4;

    size_t firstTag = FindFirstAllDistinctSubstringEndIndex(*inputFile, bufferMaxSize);

    return std::to_string(firstTag);
}

std::string Day6::DoSolvePart2() const {
    const auto inputFile = OpenInputFile();

    constexpr size_t bufferMaxSize = 14;

    size_t firstTag = FindFirstAllDistinctSubstringEndIndex(*inputFile, bufferMaxSize);

    return std::to_string(firstTag);
}

size_t Day6::FindFirstAllDistinctSubstringEndIndex(std::ifstream &file, size_t bufferMaxSize) {
    std::deque<char> buffer;

    size_t firstTag = bufferMaxSize;
    MoveBufferForwards(buffer, file, bufferMaxSize, bufferMaxSize);

    bool isEndOfFile = false;
    do {
        const size_t forwardInvalids = GetMinimalDistanceToPotentialValidPosition(buffer, bufferMaxSize);
        if ( !forwardInvalids ) break;

        isEndOfFile = !MoveBufferForwards( buffer, file, forwardInvalids, bufferMaxSize );
        firstTag += forwardInvalids;

    } while ( ! isEndOfFile );

    return firstTag;
}

size_t Day6::GetMinimalDistanceToPotentialValidPosition(const std::deque<char> &buffer, const size_t bufferMaxSize) {
    size_t forwardInvalids = 0;
    for ( auto i=bufferMaxSize-1; i>0; i-- ) {
        for ( auto j=0; j<i; j++ ) {
            if ( buffer[i] == buffer[j] ) {
                forwardInvalids = j + 1;
                break;
            }
        }
        if ( forwardInvalids ) break;
    }
    return forwardInvalids;
}

bool Day6::MoveBufferForwards(std::deque<char> &buffer, std::ifstream &file, const size_t distance, const size_t bufferMaxSize) {
    for ( size_t i=0; i<distance; i++ ) {
        char item;
        if ( ! file.get(item) ) {
            return false;
        }
        AddToQueue(item, buffer, bufferMaxSize);
    }
    return true;
}

void Day6::AddToQueue(char item, std::deque<char> &queue, const size_t queueMaxSize) {
    queue.push_back(item);
    if ( queue.size() > queueMaxSize ) queue.pop_front();
}
