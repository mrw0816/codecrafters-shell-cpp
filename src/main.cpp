#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

#include "commands/Command.h"
#include "commands/EchoCommand.h"
#include "commands/TypeCommand.h"
#include "commands/ExitCommand.h"
#include "commands/Executable.h"

int main() {
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    std::unordered_map<std::string, std::unique_ptr<Command>> commands;
    commands["exit"] = std::make_unique<ExitCommand>();
    commands["echo"] = std::make_unique<EchoCommand>();
    commands["type"] = std::make_unique<TypeCommand>(commands);

    // TODO: Uncomment the code below to pass the first stage

    while(true)
    {
        std::cout << "$ ";
        std::string inputText;
        std::getline(std::cin, inputText);

        std::istringstream input(inputText);
        std::string cmd;
        std::string args;

        input >> cmd;
        std::getline(input, args);
        if (commands.contains(cmd))
        {
            commands[cmd]->execute(args);
        }
        else if(Command::exeInPath(cmd))
        {
            Executable exe(cmd);
            exe.execute(args);
        }
        else
        {
            std::cout << cmd << ": command not found" << std::endl;
        }
    }
}
