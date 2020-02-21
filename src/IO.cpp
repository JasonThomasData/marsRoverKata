#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <iostream>
#include "io.hpp"
#include "simulation/directions.hpp"

void IO::displayInitialisationUsage()
{
    const std::string usage = "correct usage: ./bin/simulation <PLANET_WIDTH> <PLANET_HEIGHT> <NUMBER_OF_OBSTACLES> <ROBOT_COORDINATE_FROM_TOP> <ROBOT_COORDINATE_FROM_LEFT> <ROBOT_DIRECTION>";
    const std::string example = "eg: ./bin/simulation 10 12 5 4 5 south";
    std::cout<< std::endl;
    std::cout<< usage<< std::endl;
    std::cout<< example<< std::endl;
    std::cout<< std::endl;
}

void IO::checkNumberOfArgsIsValid(int& argc)
{
    const int requiredArgs = 7;
    if (argc != requiredArgs)
    {
        throw std::invalid_argument("Incorrect number of args");
    }
}

void IO::checkIsPositiveInteger(const std::string& arg)
{
    for (int i = 0; i < arg.length(); i++) 
    {
        if (isdigit(arg[i]) == false) 
        {
            throw std::invalid_argument("Valid arguments are positive integers");
        }
    }
}

int IO::getNumericArgument(const std::string& arg)
{
    checkIsPositiveInteger(arg);
    const int number = std::stoi(arg);
    return number;
}

void IO::toLowercaseString(std::string& arg)
{
    std::transform(
        arg.begin(),
        arg.end(),
        arg.begin(),
        [](unsigned char c){ return std::tolower(c); });
}

Direction IO::getDirection(std::string arg)
{
    toLowercaseString(arg);
    if (arg == "north")
    {
        return Direction::north;
    }
    else if (arg == "east")
    {
        return Direction::east;
    }
    else if (arg == "south")
    {
        return Direction::south;
    }
    else if (arg == "west")
    {
        return Direction::west;
    }
    else
    {
        throw std::invalid_argument("Valid directions are: north, east, south, west");
    }
}

StartupConfigs IO::getStartupConfigs(int& argc, char* argv[])
{
    checkNumberOfArgsIsValid(argc);

    const PlanetConfig planetConfig = { getNumericArgument(argv[1]), getNumericArgument(argv[2]), getNumericArgument(argv[3]) };
    const Coordinates robotCoordinates = { getNumericArgument(argv[4]), getNumericArgument(argv[5]) };
    const RobotConfig robotConfig = { std::move(robotCoordinates), getDirection(argv[6]) };
    const StartupConfigs startupConfigs = StartupConfigs(std::move(planetConfig), std::move(robotConfig));

    return startupConfigs;
}
