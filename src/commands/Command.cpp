
#include "Command.h"
#include <iostream>

void Command::trim(std::string& line)
{
    //Trim leading spaces
    size_t first = line.find_first_not_of(WHITESPACE);
    if(first == std::string::npos)
    {
        line.clear();
        return;
    }
    line.erase(0, first);

    //Trim trailing spaces
    size_t last = line.find_last_not_of(WHITESPACE);
    if(last != std::string::npos)
    {
        line.erase(last + 1);
    }
}
