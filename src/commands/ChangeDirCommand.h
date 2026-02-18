
#ifndef CHANGEDIRCOMMAND_H
#define CHANGEDIRCOMMAND_H

#include "Command.h"
#include <iostream>

class ChangeDirCommand : public Command
{
public:

    ChangeDirCommand() : Command() {}

    void execute(std::string args) override;

};

#endif
