#ifndef ADVENT_OF_CODE_2022_FILE_H
#define ADVENT_OF_CODE_2022_FILE_H

#include "../FileSystemNode/FileSystemNode.h"

class File final : public FileSystemNode {

public:
    explicit File(size_t size);

    bool IsAFile() override;
    bool IsADirectory() override;

};

#endif //ADVENT_OF_CODE_2022_FILE_H