#ifndef ADVENT_OF_CODE_2022_DIRECTORY_H
#define ADVENT_OF_CODE_2022_DIRECTORY_H

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "../FileSystemNode/FileSystemNode.h"

class Directory final : public FileSystemNode {

public:
    Directory();

    bool IsAFile() override;
    bool IsADirectory() override;

    void AddToSize(size_t size);

    Directory* GetChildDirectory(std::string_view name);
    bool AddChild(std::string_view nameView, std::unique_ptr<FileSystemNode> &child);

    std::vector<Directory*> GetAllChildDirectory();

private:
    std::unordered_map<std::string, std::unique_ptr<FileSystemNode>> children;

};

#endif //ADVENT_OF_CODE_2022_DIRECTORY_H