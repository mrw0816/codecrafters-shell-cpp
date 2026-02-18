
#include "PrintWorkingDirCommand.h"

void PrintWorkingDirCommand::execute(std::string args)
{
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::cout << currentPath.string() << std::endl;
}
