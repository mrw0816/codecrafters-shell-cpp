#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // TODO: Uncomment the code below to pass the first stage

    while(true)
    {
        std::cout << "$ ";
        std::string inputText;
        std::getline(std::cin, inputText);

        std::istringstream input(inputText);
        std::string command;
        std::string args;

        input >> command;
        std::getline(input, args);

        if(command == "exit")
        {
            std::exit(0);
        }
        else if(command == "echo")
        {
            std::cout << args << "\n";
        }
        else
        {
            std::cout << command << ": command not found" << std::endl;
        }
    }
}
