#include <string>

#include "configs/startup-config.hpp"
#include "simulation/directions.hpp"


namespace IO
{
    void displayInitialisationUsage();
    void checkNumberOfArgsIsValid(int& argc);
    void checkIsPositiveInteger(const std::string& arg);
    int getNumericArgument(const std::string& arg);
    void toLowercaseString(std::string& arg);
    StartupConfigs getStartupConfigs(int& argc, char* argv[]);
    Direction getDirection(std::string arg);
}
