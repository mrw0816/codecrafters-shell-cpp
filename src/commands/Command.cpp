
#include "Command.h"
#include <iostream>

namespace fs = std::filesystem;

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

bool Command::exeInPath(std::string command)
{
    fs::path dummy;
    return exeInPath(command, dummy);
}

bool Command::exeInPath(std::string command, std::filesystem::path& exePath)
{
    std::vector<std::string> entries = getAndParsePath();

    //struct stat sb;
    //loop through path entries
    fs::path path;
    std::error_code ec;
    fs::file_status f_status;
    fs::perms f_perms;
    for(const auto entry : entries)
    {
        try
        {
            path = fs::path(entry); 
            //Check if entry is a directory
            if(fs::is_directory(path))
            {
                fs::path entryInDir = fs::path(path.string() + "/" + command);
                //Does entryInDir exist and is it a regular file?
                if(fs::exists(entryInDir) && fs::is_regular_file(entryInDir))
                {
                    f_status = fs::status(entryInDir, ec);
                    //Error. Just continue for now
                    if(ec)
                    {
                        continue;
                    }
                    
                    //Check for executable permissions
                    fs::perms f_perms = f_status.permissions();
                    if((fs::perms::owner_exec  & f_perms) != fs::perms::none)// ||
                        //(fs::perms::group_exec  & f_perms) != fs::perms::none ||
                        //(fs::perms::others_exec & f_perms) != fs::perms::none)
                    {
                        exePath = fs::path(entryInDir);
                        return true;
                    }
                }
            }
            else if(fs::is_regular_file(path))
            {
                f_status = fs::status(path, ec);
                //Error. Just continue for now
                if(ec)
                {
                    continue;
                }

                //Check for executable permissions
                fs::perms f_perms = f_status.permissions();
                if((fs::perms::owner_exec  & f_perms) != fs::perms::none) //||
                    //(fs::perms::group_exec  & f_perms) != fs::perms::none ||
                    //(fs::perms::others_exec & f_perms) != fs::perms::none)
                {
                    exePath = fs::path(path);
                    return true;
                } 
            }
        }
        catch(std::filesystem::filesystem_error const& error)
        {
            //std::fprintf(stderr, "Caught exception : %s\n", error.what());
        }
    }
    return false;    
}

std::vector<std::string> Command::getAndParsePath()
{
    const char* path = std::getenv("PATH");

    std::vector<std::string> entries;
    std::stringstream ss(path);
    std::string item;

    while(std::getline(ss, item, SEPARATOR))
    {
        if(!item.empty())
            entries.push_back(item);
    }

    return entries;
}

