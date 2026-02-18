
#include "ChangeDirCommand.h"
#include <unistd.h>

void ChangeDirCommand::execute(std::string args)
{
    trim(args);
    chdir(args.c_str());
}
