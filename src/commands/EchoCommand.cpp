
#include "EchoCommand.h"

void EchoCommand::execute(std::string args)
{
    trim(args);
    std::cout << args << std::endl;
}

