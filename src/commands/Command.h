#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <filesystem>

class Command {

public:

    Command(){}
    virtual ~Command() = default;
    
    virtual void execute(std::string args) = 0;
   
    void trim(std::string& line);
   
    static bool exeInPath(std::string command);
    static bool exeInPath(std::string command, std::filesystem::path& exePath);
    static std::vector<std::string> getAndParsePath();

private:

    const std::string WHITESPACE = " \n\r\t\f\v";

#ifdef _WIN32
    static const char SEPARATOR = ';';
#else
    static const char SEPARATOR = ':';
#endif

};

#endif
