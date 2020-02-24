#include <sstream>
#include <vector>
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

std::vector<Movement> Robot::interpretInstructions(const std::string& instructions)
{
    std::vector<Movement> movements;
    for(const char& instruction : instructions)
    {
        Movement movement = getMovementInstruction(instruction);
        movements.push_back(movement);
    }
    return movements;
}

Movement Robot::getMovementInstruction(const char& instruction)
{
    if (instruction == 'f')
    {
        return Movement::forward;
    }
    else if (instruction == 'b')
    {
        return Movement::backward;
    }
    else if (instruction == 'l')
    {
        return Movement::left;
    }
    else if (instruction == 'r')
    {
        return Movement::right;
    }
    else
    {
        std::ostringstream errorMessage;
        errorMessage<< "The instruction \'"<< instruction<< "\' is not valid. \n Valid instructions are: f (forward), b (backward), l (left), r (right)";
        throw std::invalid_argument(errorMessage.str());
    }
}

Robot::Robot(std::unique_ptr<IPlanet> planet, RobotConfig robotConfig)
    :planet(std::move(planet)),
    coordinates(std::move(robotConfig.coordinates)),
    direction(std::move(robotConfig.direction))
{
    validateRobotCoordinates(robotConfig.coordinates);
}

Robot::Robot(){};
