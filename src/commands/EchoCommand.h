
#ifndef ECHOCOMMAND_H
#define ECHOCOMMAND_H

#include "Command.h"
#include <iostream>

class EchoCommand : public Command
{

public:

    EchoCommand() : Command(Type::Builtin) {}

    void execute(std::string args) override;
 
};

#endif

