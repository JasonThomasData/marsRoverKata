#include "configs/StartupConfigs.hpp"

namespace IO
{
    void displayUsage();
    void checkIsPositiveInteger(std::string arg);
    int getNumericArgument(std::string arg);
    StartupConfigs getStartupConfigs(int argc, char* argv[]);
}
