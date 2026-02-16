
#include "TypeCommand.h"
#include <iostream>
#include <sstream>
#include <experimental/filesystem>
#include <filesystem>

namespace fs = std::filesystem;

TypeCommand::TypeCommand(const std::unordered_map<std::string, Command*>& cmds) :
    Command(Type::Builtin),
    commands(cmds)
{
}

void TypeCommand::execute(std::string args)
{
    trim(args);

    if (commands.contains(args))
    {
       std::cout << args << " is a shell builtin" << std::endl; 
    }
    else
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
                    fs::path pathToCheck = fs::path(path.string() + "/" + args);
                    //Does pathToCheck exist and is it a regular file?
                    if(fs::exists(pathToCheck) && fs::is_regular_file(pathToCheck))
                    {
                        f_status = fs::status(pathToCheck, ec);
                        //Error. Just continue for now
                        if(ec)
                        {
                            continue;
                        }
                        //Check for executable permissions
                        if((fs::perms::owner_exec  & f_perms) != fs::perms::none ||
                            (fs::perms::group_exec  & f_perms) != fs::perms::none ||
                            (fs::perms::others_exec & f_perms) != fs::perms::none)
                        {
                            std::cout << args << " is " << pathToCheck.string() << std::endl;
                            return;
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
                    if((fs::perms::owner_exec  & f_perms) != fs::perms::none ||
                        (fs::perms::group_exec  & f_perms) != fs::perms::none ||
                        (fs::perms::others_exec & f_perms) != fs::perms::none)
                    {
                        std::cout << args << " is " << path.string() << std::endl;
                        return;
                    } 
                }
            }
            catch(std::filesystem::filesystem_error error)
            {
            }

            
            /*
            //Check if entry is exists
            if(access(entry.c_str(), F_OK) == 0)
            {
                //do something here
                std::cout << "wat";
            }
            */
        }
        std::cout << args << ": not found" << std::endl;
    }

}

std::vector<std::string> TypeCommand::getAndParsePath()
{
    char separator = ':';
    const char* path = std::getenv("PATH");

    std::vector<std::string> entries;
    std::stringstream ss(path);
    std::string item;

    while(std::getline(ss, item, separator))
    {
        if(!item.empty())
            entries.push_back(item);
    }

    for (const auto& e: entries)
    {
        std::cout << e << "\n";
    }

    return entries;
}
