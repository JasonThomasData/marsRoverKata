#include "configs/StartupConfigs.hpp"

namespace IO
{
    void checkIsNumeric(std::string arg);
    void checkIsPositive(int number);
    int getNumericArgument(std::string arg);
    StartupConfigs getStartupConfigs(char* argv[]);
}
