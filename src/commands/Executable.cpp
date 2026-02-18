
#include <iostream>
#include "Executable.h"

Executable::Executable(std::string exe) :
    m_exeName(exe)
{
}

void Executable::execute(std::string args)
{
    trim(args);
    std::cout << m_exeName << " " << args << std::endl;
    std::system((m_exeName + " " + args).c_str());
}
