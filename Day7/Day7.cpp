#include "Day7.h"

#include "Directory/Directory.h"
#include "File/File.h"

Day7::Day7() : BaseDay(7) {
}

std::string Day7::DoSolvePart1() const {
    const auto inputFile = OpenInputFile();

    constexpr char commandToken = '$';

    const auto root = BuildFileSystemFromFile(inputFile, commandToken);

    size_t sum = 0;
    std::vector stack = {root.get()};

    while ( !stack.empty() ) {
        Directory* dir = stack.back();
        stack.pop_back();

        const auto dirSize = dir->GetSize();
        if (dirSize <= 100000) sum += dirSize;

        for (Directory* childDir : dir->GetAllChildDirectory()) {
            stack.push_back(childDir);
        }
    }

    return std::to_string(sum);
}

std::string Day7::DoSolvePart2() const {
    const auto inputFile = OpenInputFile();

    constexpr char commandToken = '$';

    const auto root = BuildFileSystemFromFile(inputFile, commandToken);

    constexpr size_t totalSize = 70000000;
    constexpr size_t neededFreeSize = 30000000;

    const auto usedSize = root->GetSize();
    const auto freeSize = totalSize - usedSize;
    const auto toFreeSize = neededFreeSize - freeSize;

    size_t betterDirSize = usedSize;
    std::vector stack = {root.get()};

    while ( !stack.empty() ) {
        Directory* dir = stack.back();
        stack.pop_back();

        const auto dirSize = dir->GetSize();
        if (dirSize >= toFreeSize && dirSize < betterDirSize) betterDirSize = dirSize;

        for (Directory* childDir : dir->GetAllChildDirectory()) {
            stack.push_back(childDir);
        }
    }

    return std::to_string(betterDirSize);
}

std::unique_ptr<Directory> Day7::BuildFileSystemFromFile(const std::unique_ptr<std::ifstream> &inputFile, const char commandToken) {
    auto root = std::make_unique<Directory>();

    Directory* currentDirectory = root.get();
    auto expectedDataType = None;

    size_t lineCount = 1;
    for (std::string line; std::getline(*inputFile, line); lineCount++) {
        auto tokens = Split(line, ' ');
        if ( tokens.empty() ) continue;

        if ( IsACommand(tokens, commandToken, lineCount) ) {
            ExecuteCommand(tokens, lineCount, root, currentDirectory, expectedDataType);

        } else {
            HandleData(tokens, lineCount, expectedDataType, currentDirectory);
        }
    }

    return root;
}

bool Day7::IsACommand(const std::vector<std::string_view> &tokens, const char commandToken, const size_t line) {
    const auto& firstToken = tokens.at(0);

    const bool isCommandToken = firstToken.size() == 1 && firstToken.at(0) == commandToken;
    if ( !isCommandToken ) return false;

    const bool containTheCommand = tokens.size() >= 2 ;
    if ( !containTheCommand ) throw std::runtime_error(std::format("Command token \"{}\" was found but with no following command at line {}.", commandToken, line));

    return true;
}

void Day7::ExecuteCommand(const std::vector<std::string_view> &tokens, size_t lineCount, const std::unique_ptr<Directory> &root, Directory *&currentDirectory, DataType &expectedDataType) {
    const std::string_view command = tokens.at(1);

    if ( command == "cd" ) {
        std::vector<std::string_view>::value_type destination;
        ExecuteCDCommand(tokens, lineCount, root, currentDirectory, destination);

        if ( !currentDirectory )  throw std::runtime_error(std::format("Try to move in the \"{}\" unknow destination at line {}.", destination, lineCount));
        expectedDataType = None;

    } else if ( command == "ls" ) {
        expectedDataType = LsResult;

    } else {
        throw std::runtime_error(std::format("Unknow command : \"{}\" at line {}.", std::string(command), lineCount));
    }
}

void Day7::ExecuteCDCommand(const std::vector<std::string_view> &tokens, size_t lineCount, const std::unique_ptr<Directory> &root, Directory *&currentDirectory, std::vector<std::string_view>::value_type &destination_copy) {
    const bool containDestination = tokens.size() == 3;
    if ( !containDestination ) throw std::runtime_error(std::format("Command \"cd\" was found but without destination at line {}.", lineCount));
    auto& destination = tokens.at(2);

    if ( destination == "/" ) {
        currentDirectory = root.get();

    } else if ( destination == ".." ) {
        currentDirectory = currentDirectory->GetParent();

    } else {
        currentDirectory = currentDirectory->GetChildDirectory(destination);
    }
    destination_copy = destination;
}

void Day7::HandleData(const std::vector<std::string_view> &tokens, size_t lineCount, const DataType expectedDataType, Directory *currentDirectory) {
    switch ( expectedDataType ) {
        case None :
            throw std::runtime_error(std::format("Unexpected data where read at line {}.", lineCount));

        case LsResult : {
            HandleLsData(tokens, lineCount, currentDirectory);
        }
            break;
    }
}

void Day7::HandleLsData(const std::vector<std::string_view> &tokens, size_t lineCount, Directory *currentDirectory) {
    const auto containsAllData = tokens.size()>=2;
    if ( !containsAllData ) throw std::runtime_error(std::format("Unexpected data where read at line {}.",lineCount));

    if ( tokens.at(0) == "dir" ) {
        const auto name = tokens.at(1);
        std::unique_ptr<FileSystemNode> newDir = std::make_unique<Directory>();
        currentDirectory->AddChild(name, newDir);

    } else { //File
        const auto name = tokens.at(1);
        const auto sizeStr = tokens.at(0).data();
        const auto size = std::stoull(sizeStr);
        std::unique_ptr<FileSystemNode> newFile = std::make_unique<File>(size);
        currentDirectory->AddChild(name, newFile);
    }
}

std::vector<std::string_view> Day7::Split(std::string &string, const char token) {
    std::vector<std::string_view> tokens;
    size_t start = 0;
    size_t end = string.find(token);

    while ( end!=std::string::npos ) {
        tokens.emplace_back( string.data() + start, end - start );
        start = end + 1;
        end = string.find(token, start);
    }
    tokens.emplace_back( string.data() + start, string.size() - start );

    return tokens;
}
