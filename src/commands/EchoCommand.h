
#ifndef ECHOCOMMAND_H
#define ECHOCOMMAND_H

#include "Command.h"
#include <iostream>

class EchoCommand : public Command
{

public:

    EchoCommand();

    void execute(std::string args) override;

private:
    
    std::string args;
};

#endif

