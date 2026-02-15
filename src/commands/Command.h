#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {

public:

    enum Type
    {
        Builtin,
        External,
        Unknown
    };

    Command(Type t) : type(t) {}
    virtual ~Command() = default;
    
    virtual void execute(std::string args) = 0;
   
    Type getType() const { return type; }
    void trim(std::string& line);

private:

    const std::string WHITESPACE = " \n\r\t\f\v";

    Type type;
};

#endif
