
#include "TypeCommand.h"
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;

TypeCommand::TypeCommand(const std::unordered_map<std::string, Command*>& cmds) :
    Command(Type::Builtin),
    commands(cmds)
{
}

void TypeCommand::execute(std::string args)
{
    trim(args);

    std::filesystem::path exePath;
    if (commands.contains(args))
    {
       std::cout << args << " is a shell builtin" << std::endl; 
    }
    else if(exeInPath(args, exePath))
    {
        std::cout << args << " is " << exePath.string() << std::endl;
    }
    else
    {
        std::cout << args << ": not found" << std::endl;
    }

}

