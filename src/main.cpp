#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

#include "commands/Command.h"
#include "commands/EchoCommand.h"
#include "commands/TypeCommand.h"
#include "commands/ExitCommand.h"

int main() {
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    std::unordered_map<std::string, Command*> commands;
    commands["exit"] = new ExitCommand();
    commands["echo"] = new EchoCommand();
    commands["type"] = new TypeCommand(commands);

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
        else
        {
            std::cout << cmd << ": command not found" << std::endl;
        }
    }
}
