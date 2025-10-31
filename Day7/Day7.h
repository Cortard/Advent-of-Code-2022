#ifndef ADVENT_OF_CODE_2022_DAY7_H
#define ADVENT_OF_CODE_2022_DAY7_H
#include "../BaseDay/BaseDay.h"
#include "Directory/Directory.h"


class Day7 final : public BaseDay {

public:
    Day7();

protected:
    [[nodiscard]] std::string DoSolvePart1() const override;
    [[nodiscard]] std::string DoSolvePart2() const override;

private:
    static std::unique_ptr<Directory> BuildFileSystemFromFile(const std::unique_ptr<std::ifstream> &inputFile, char commandToken);

    enum DataType { None = 0, LsResult = 1 };

    static bool IsACommand(const std::vector<std::string_view> &tokens, char commandToken, size_t line);
    static void ExecuteCommand(const std::vector<std::string_view> &tokens, size_t lineCount, const std::unique_ptr<Directory> &root, Directory *&currentDirectory, DataType &expectedDataType) ;
    static void ExecuteCDCommand(const std::vector<std::string_view> &tokens, size_t lineCount, const std::unique_ptr<Directory> &root, Directory *&currentDirectory, std::vector<std::string_view>::value_type &destination_copy);

    static void HandleData(const std::vector<std::string_view> &tokens, size_t lineCount, DataType expectedDataType, Directory *currentDirectory);
    static void HandleLsData(const std::vector<std::string_view> &tokens, size_t lineCount, Directory *currentDirectory);

    static std::vector<std::string_view> Split(std::string &string, char token);

};


#endif //ADVENT_OF_CODE_2022_DAY7_H