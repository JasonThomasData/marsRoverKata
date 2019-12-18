#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <iostream>
#include "IO.hpp"

void IO::checkIsNumeric(std::string arg)
{
    for (int i = 0; i < arg.length(); i++) 
    {
        if (isdigit(arg[i]) == false) 
        {
            throw std::invalid_argument("Valid arguments are integers");
        }
    }
}

void IO::checkIsPositive(int number)
{
    if (number <= 0)
    {
        throw std::invalid_argument("Valid arguments are positive integers");
    }
}

int IO::getNumericArgument(std::string arg)
{
    checkIsNumeric(arg);
    int number = std::stoi(arg);
    checkIsPositive(number);
    return number;
}

StartupConfigs IO::getStartupConfigs(char* argv[])
{
    PlanetConfig planetConfig;
    planetConfig.surfaceWidth = getNumericArgument(argv[1]);
    planetConfig.surfaceHeight = getNumericArgument(argv[2]);
    planetConfig.obstacleNumber = getNumericArgument(argv[3]);

    RobotConfig robotConfig;
    robotConfig.x_coordinate = getNumericArgument(argv[4]);
    robotConfig.y_coordinate = getNumericArgument(argv[5]);

    StartupConfigs startupConfigs = { planetConfig, robotConfig };
    return startupConfigs;
}
