
#ifndef ECHOCOMMAND_H
#define ECHOCOMMAND_H

#include "Command.h"
#include <iostream>

class EchoCommand : public Command
{

public:

    EchoCommand() : Command() {}

    void execute(std::string args) override;
 
};

#endif

