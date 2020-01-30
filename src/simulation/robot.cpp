#include <sstream>
#include <stdexcept>
#include "coordinates.hpp"
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

Robot::Robot(std::unique_ptr<IPlanet> planet, RobotConfig robotConfig)
    :planet(std::move(planet)),
    coordinates(std::move(robotConfig.coordinates))
{
    validateRobotCoordinates(robotConfig.coordinates);
}

Robot::Robot(){};
