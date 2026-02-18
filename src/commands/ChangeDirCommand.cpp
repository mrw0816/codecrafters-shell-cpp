
#include "ChangeDirCommand.h"
#include <unistd.h>

void ChangeDirCommand::execute(std::string args)
{
    trim(args);
    std::filesystem::path dir(args);
    
    if(std::filesystem::is_directory(dir))
    {
        chdir(args.c_str());
    }
    else
    {
        std::cout << "cd: " << args << ": No such file or directory" << std::endl;
    }
}
