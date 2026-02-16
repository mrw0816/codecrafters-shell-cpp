
#include <iostream>
#include "Executable.h"

Executable::Executable(std::string exe) :
    exeName(exe)
{
}

void Executable::execute(std::string args)
{
    std::cout << "args = " << args << std::endl;
}
