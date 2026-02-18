
#include <iostream>
#include "Executable.h"

Executable::Executable(std::string exe) :
    m_exeName(exe)
{
}

void Executable::execute(std::string args)
{
    trim(args);
    std::system((m_exeName + " " + args).c_str());
}
