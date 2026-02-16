#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <filesystem>

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

protected:
    
    bool exeInPath(std::string command, std::filesystem::path& exePath);
    std::vector<std::string> getAndParsePath();

private:

    const std::string WHITESPACE = " \n\r\t\f\v";

#ifdef _WIN32
    const char SEPARATOR = ';';
#else
    const char SEPARATOR = ':';
#endif

    Type type;

};

#endif
