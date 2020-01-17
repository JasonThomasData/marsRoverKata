#include <sstream>
#include <stdexcept>
#include "coordinates.hpp"
#include "i_planet.hpp"
#include "robot.hpp"
#include "../configs/robot-config.hpp"

void Robot::establishRobotCoordinates(RobotConfig robotConfig)
{
    coordinates = robotConfig.coordinates;

    if(planet->isObstacleAtCoordinate(coordinates))
    {
        std::ostringstream errorMessage;
        errorMessage<< "There is an obstacle at your preferred starting point, so the robot is at "<< coordinates.fromTop<< " from top and "<< coordinates.fromLeft<< " from left, instead."; 
        throw std::invalid_argument(errorMessage.str());
    }
}

Robot::Robot(std::unique_ptr<IPlanet> planet, RobotConfig robotConfig)
    :planet(std::move(planet))
{
    establishRobotCoordinates(robotConfig);
}

Robot::Robot(){};
