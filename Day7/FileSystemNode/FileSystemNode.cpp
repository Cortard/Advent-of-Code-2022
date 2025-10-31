#include "FileSystemNode.h"

#include "../Directory/Directory.h"

size_t FileSystemNode::GetSize() {
    return size;
}

void FileSystemNode::SetSize(const size_t newSize) {
    if ( parent ) parent->AddToSize( newSize - size );
    size = newSize;
}

Directory * FileSystemNode::GetParent() {
    return parent;
}

void FileSystemNode::SetParent(Directory *newParent) {
    parent = newParent;
}

FileSystemNode::FileSystemNode(const size_t size) : size(size), parent(nullptr) {
}

FileSystemNode::FileSystemNode(const size_t size, Directory *parent) : size(size), parent(parent) {
}
