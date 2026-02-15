
#ifndef TYPECOMMAND_H
#define TYPECOMMAND_H

#include "Command.h"
#include <iostream>
#include <unordered_map>

class TypeCommand : public Command
{

public:

    TypeCommand(const std::unordered_map<std::string, Command*>& cmds);

    void execute(std::string args) override;

private:
    
    const std::unordered_map<std::string, Command*>& commands;
};

#endif
