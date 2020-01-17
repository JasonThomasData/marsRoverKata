#include <sstream>
#include <stdexcept>
#include "planet.hpp"
#include "surface-square.hpp"
#include "../configs/planet-config.hpp"

void Planet::checkConfigsValid(PlanetConfig planetConfig)
{
    int surfaceArea = planetConfig.surfaceHeight * planetConfig.surfaceWidth;
    if(planetConfig.obstacleNumber >= surfaceArea)
    {
        std::ostringstream errorMessage;
        errorMessage<< "There is no room to place the robot on this surface area of"<< surfaceArea<< " and "<< planetConfig.obstacleNumber<< " obstacles."; 
        throw std::invalid_argument(errorMessage.str());
    }
}

void Planet::createSurface(PlanetConfig planetConfig)
{
    for(int i = 0; i < planetConfig.surfaceHeight; i++)
    {
        std::vector<SurfaceSquare> sliceOfSurfaceSpanningWidthOfPlanet;
        for(int j = 0; j < planetConfig.surfaceWidth; j++)
        {
            sliceOfSurfaceSpanningWidthOfPlanet.push_back(SurfaceSquare::null);
        }
        surface.push_back(sliceOfSurfaceSpanningWidthOfPlanet);
    }
};

void Planet::createObstacles(PlanetConfig planetConfig)
{
    while(numberOfObstacles < planetConfig.obstacleNumber)
    {
        int fromTop = rand() % planetConfig.surfaceHeight;
        int fromLeft = rand() % planetConfig.surfaceWidth;
        if(surface[fromTop][fromLeft] != SurfaceSquare::obstacle)
        {
            surface[fromTop][fromLeft] = SurfaceSquare::obstacle;
            numberOfObstacles++;
        }
    }
};

bool Planet::isObstacleAtCoordinate(int fromTop, int fromLeft)
{
    if(surface[fromTop][fromLeft] == SurfaceSquare::obstacle)
    {
        return true;
    };
    return false;
}

int Planet::countObstaclesOnSurface()
{
    return numberOfObstacles;
}

Planet::Planet(PlanetConfig planetConfig)
{
    numberOfObstacles = 0;
    checkConfigsValid(planetConfig);
    createSurface(planetConfig);
    createObstacles(planetConfig);
}

Planet::Planet(){};
