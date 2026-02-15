
#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "Command.h"
#include <iostream>

class ExitCommand : public Command
{
public:

    ExitCommand() : Command(Type::Builtin) {}

    void execute(std::string args) override;
};

#endif
