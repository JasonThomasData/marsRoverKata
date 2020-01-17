#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <iostream>
#include "io.hpp"

void IO::displayInitialisationUsage()
{
    const std::string usage = "correct usage: ./bin/simulation <PLANET_WIDTH> <PLANET_HEIGHT> <NUMBER_OF_OBSTACLES> <ROBOT_X_COORDINATE> <ROBOT_Y_COORDINATE>";
    const std::string example = "eg: ./bin/simulation 10 12 5 4 5";
    std::cout<< std::endl;
    std::cout<< usage<< std::endl;
    std::cout<< example<< std::endl;
    std::cout<< std::endl;
}

void IO::checkIsPositiveInteger(std::string arg)
{
    for (int i = 0; i < arg.length(); i++) 
    {
        if (isdigit(arg[i]) == false) 
        {
            throw std::invalid_argument("Valid arguments are positive integers");
        }
    }
}

int IO::getNumericArgument(std::string arg)
{
    checkIsPositiveInteger(arg);
    const int number = std::stoi(arg);
    return number;
}

StartupConfigs IO::getStartupConfigs(int argc, char* argv[])
{
    const int requiredArgs = 6;
    if (argc != requiredArgs)
    {
        throw std::invalid_argument("Incorrect number of args");
    }

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
