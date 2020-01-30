#include <sstream>
#include <stdexcept>

#include "planet-config.hpp"
#include "robot-config.hpp"
#include "startup-config.hpp"

void StartupConfigs::checkObstaclesFewerThanSurfaceArea()
{
    int surfaceArea = planet.surfaceHeight * planet.surfaceWidth;
    if(planet.obstacleNumber > surfaceArea)
    {
        std::ostringstream errorMessage;
        errorMessage<< "There is no room to place all of the obstacles on this planet (surface area of "<< surfaceArea<< " and "<< planet.obstacleNumber<< " obstacles)."; 
        throw std::invalid_argument(errorMessage.str());
    }
}

void StartupConfigs::checkSpaceForRobot()
{
    int surfaceArea = planet.surfaceHeight * planet.surfaceWidth;
    if(planet.obstacleNumber == surfaceArea)
    {
        std::ostringstream errorMessage;
        errorMessage<< "There is no room to place the robot on this planet (surface area of "<< surfaceArea<< " and "<< planet.obstacleNumber<< " obstacles)."; 
        throw std::invalid_argument(errorMessage.str());
    }
}

void StartupConfigs::checkRobotIsOnSurface()
{
    bool onSurface = robot.coordinates.fromLeft >= 0 
        && robot.coordinates.fromLeft < planet.surfaceWidth 
        && robot.coordinates.fromTop >= 0
        && robot.coordinates.fromTop < planet.surfaceHeight;

    if(!onSurface)
    {
        std::ostringstream errorMessage;
        errorMessage<< "The robot at "<< robot.coordinates.fromTop<<" and "<< robot.coordinates.fromLeft<<" is not within the planet's surface limits of "<< planet.surfaceWidth<< " and "<< planet.surfaceHeight<< std::endl; 
        throw std::invalid_argument(errorMessage.str());
    }
}

StartupConfigs::StartupConfigs(const PlanetConfig planetConfig, const RobotConfig robotConfig)
    :planet(std::move(planetConfig)),
    robot(std::move(robotConfig))
{
    checkObstaclesFewerThanSurfaceArea();
    checkSpaceForRobot();
    checkRobotIsOnSurface();
}

StartupConfigs::StartupConfigs(){};