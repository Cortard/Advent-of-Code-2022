#include "File.h"

File::File(const size_t size) : FileSystemNode(size)  {
}

bool File::IsAFile() {
    return true;
}

bool File::IsADirectory() {
    return false;
}
