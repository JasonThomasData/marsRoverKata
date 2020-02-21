#include <sstream>
#include <stdexcept>
#include "coordinates.hpp"
#include "directions.hpp"
#include "movements.hpp"
#include "i_planet.hpp"
#include "robot.hpp"
#include "../configs/robot-config.hpp"

void Robot::validateRobotCoordinates(const Coordinates& potentialCoordinates)
{
    if(planet->isObstacleAtCoordinate(potentialCoordinates))
    {
        std::ostringstream errorMessage;
        errorMessage<< "There is an obstacle at your preferred starting point. Coordinates not set."<< std::endl; 
        throw std::invalid_argument(errorMessage.str());
    }
}

std::string Robot::interpretAndApplyInstructions(const std::string& instructions)
{
    for(const char& instruction : instructions)
    {
        if (!checkInstructionIsValid(instruction))
        {
            std::ostringstream errorMessage;
            errorMessage<< "The instruction {} was invalid"<< std::endl; 
            throw std::invalid_argument(errorMessage.str());
        }
    }
    return instructions;
}

bool Robot::checkInstructionIsValid(const char& instruction)
{
    return true;
}

Robot::Robot(std::unique_ptr<IPlanet> planet, RobotConfig robotConfig)
    :planet(std::move(planet)),
    coordinates(std::move(robotConfig.coordinates)),
    direction(std::move(robotConfig.direction))
{
    validateRobotCoordinates(robotConfig.coordinates);
}

Robot::Robot(){};
