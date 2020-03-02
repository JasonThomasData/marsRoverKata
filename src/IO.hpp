#include <string>

#include "configs/startup-config.hpp"
#include "directions.hpp"


namespace IO
{
    void displayInitialisationUsage();
    void displayRobotUsage();
    void checkNumberOfArgsIsValid(int& argc);
    void checkIsPositiveInteger(const std::string& arg);
    int getNumericArgument(const std::string& arg);
    std::string toLowercaseString(const std::string& arg);
    const StartupConfigs getStartupConfigs(int& argc, char* argv[]);
    Direction getDirection(const std::string& arg);
    const std::string getUserInput();
    void returnRobotReport(const std::string& robotMoveReport);
}
