#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {

public:
    
    void trim(std::string& line);

    virtual void execute(std::string args) = 0;

    virtual ~Command() = default;

private:

    const std::string WHITESPACE = " \n\r\t\f\v";
};

#endif
