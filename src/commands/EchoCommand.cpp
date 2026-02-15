#include "EchoCommand.h"

EchoCommand::EchoCommand()
{
}

void EchoCommand::execute(std::string args)
{
    trim(args);
    std::cout << args << std::endl;
}

