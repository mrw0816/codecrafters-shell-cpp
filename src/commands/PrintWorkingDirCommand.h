
#ifndef PRINTWORKINGDIRCOMMAND_H
#define PRINTWORKINGDIRCOMMAND_H

#include "Command.h"
#include <iostream>

class PrintWorkingDirCommand : public Command
{
public:

    PrintWorkingDirCommand() : Command() {}

    void execute(std::string args) override;

};

#endif
