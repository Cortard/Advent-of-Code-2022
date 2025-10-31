#ifndef ADVENT_OF_CODE_2022_FILESYSTEMNODE_H
#define ADVENT_OF_CODE_2022_FILESYSTEMNODE_H

typedef unsigned long long size_t;

class Directory;

class FileSystemNode {

public :
    virtual bool IsAFile()=0;
    virtual bool IsADirectory()=0;

    virtual size_t GetSize();
    virtual void SetSize(size_t newSize);

    virtual Directory* GetParent();
    virtual void SetParent(Directory* newParent);

    virtual ~FileSystemNode() = default;

protected:
    size_t size;
    Directory* parent;

    explicit FileSystemNode(size_t size);
    explicit FileSystemNode(size_t size, Directory* parent);

};

#endif //ADVENT_OF_CODE_2022_FILESYSTEMNODE_H