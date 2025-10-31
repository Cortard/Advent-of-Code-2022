#include "Directory.h"

#include <algorithm>
#include <ranges>

Directory::Directory() : FileSystemNode(0), children() {
}

bool Directory::IsAFile() {
    return false;
}

bool Directory::IsADirectory() {
    return true;
}

void Directory::AddToSize(const size_t size) {
    if ( parent ) parent->AddToSize(size);
    this->size += size;
}

Directory* Directory::GetChildDirectory(const std::string_view name) {
    const auto it = children.find(name.data());
    if (it == children.end()) return nullptr;
    const auto result = it->second.get();
    if ( ! result->IsADirectory() ) return nullptr;
    return dynamic_cast<Directory *>(result);
}

bool Directory::AddChild(const std::string_view nameView, std::unique_ptr<FileSystemNode> &child) {
    const auto name = nameView.data();
    if ( child == nullptr ) return false;
    if ( children.contains(name) ) return false;

    child->SetParent(this);
    AddToSize(child->GetSize());
    children.emplace(name, std::move(child));
    return true;
}

std::vector<Directory *> Directory::GetAllChildDirectory() {
    std::vector<Directory*> result;

    for (const auto &child: children | std::views::values) {
        if (child.get()->IsADirectory()) {
            result.push_back(dynamic_cast<std::vector<Directory *>::value_type>(child.get()));
        }
    }

    return result;
}
