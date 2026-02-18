
#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "Command.h"

class Executable : public Command
{

public:

    Executable(std::string exe);

    void execute(std::string args) override;

private:

    std::string m_exeName;
 
};

#endif
