
#include "TypeCommand.h"
#include <iostream>

TypeCommand::TypeCommand(const std::unordered_map<std::string, Command*>& cmds) :
    Command(Type::Builtin),
    commands(cmds)
{
}

void TypeCommand::execute(std::string args)
{
    trim(args);

    if (commands.contains(args))
    {
       std::cout << args << " is a shell builtin" << std::endl; 
    }
    else
    {
        std::cout << args << ": not found" << std::endl;
    }

}
