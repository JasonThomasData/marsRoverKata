#include "configs/startup-config.hpp"

namespace IO
{
    void displayInitialisationUsage();
    void checkNumberOfArgsIsValid(int& argc);
    void checkIsPositiveInteger(const std::string& arg);
    int getNumericArgument(const std::string& arg);
    StartupConfigs getStartupConfigs(int& argc, char* argv[]);
}
