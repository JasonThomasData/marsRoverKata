#include <sstream>
#include <stdexcept>
#include "coordinates.hpp"
#include "i_planet.hpp"
#include "robot.hpp"
#include "../configs/robot-config.hpp"

void Robot::establishRobotCoordinates(Coordinates potentialCoordinates)
{
    if(planet->isObstacleAtCoordinate(potentialCoordinates))
    {
        std::ostringstream errorMessage;
        errorMessage<< "There is an obstacle at your preferred starting point. Coordinates not set."<< std::endl; 
        throw std::invalid_argument(errorMessage.str());
    }

    coordinates = potentialCoordinates;
}

Robot::Robot(std::unique_ptr<IPlanet> planet, RobotConfig robotConfig)
    :planet(std::move(planet))
{
    establishRobotCoordinates(std::move(robotConfig.coordinates));
}

Robot::Robot(){};
