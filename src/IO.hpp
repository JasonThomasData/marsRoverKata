#include "configs/startup-config.hpp"

namespace IO
{
    void displayInitialisationUsage();
    void checkIsPositiveInteger(std::string arg);
    int getNumericArgument(std::string arg);
    StartupConfigs getStartupConfigs(int argc, char* argv[]);
}
