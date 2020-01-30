#include <sstream>
#include <stdexcept>
#include "planet.hpp"
#include "surface-square.hpp"
#include "../configs/planet-config.hpp"

void Planet::createSurface(const PlanetConfig& planetConfig)
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

void Planet::createObstacles(const StartupConfigs& startupConfig)
{
    int numberOfObstacles = 0;
    while(numberOfObstacles < startupConfig.planet.obstacleNumber)
    {
        Coordinates obstacleCoordinates;
        obstacleCoordinates.fromTop = rand() % startupConfig.planet.surfaceHeight;
        obstacleCoordinates.fromLeft = rand() % startupConfig.planet.surfaceWidth;
        //Replace loop with a randomised list, pop off end (gauranteed to halt in n loops)
        if(surface[obstacleCoordinates.fromTop][obstacleCoordinates.fromLeft] != SurfaceSquare::obstacle
            && !obstacleCoordinates.isSame(startupConfig.robot.coordinates))
        {
            surface[obstacleCoordinates.fromTop][obstacleCoordinates.fromLeft] = SurfaceSquare::obstacle;
            numberOfObstacles++;
        }
    }
};

bool Planet::isObstacleAtCoordinate(const Coordinates& coordinates)
{
    return surface[coordinates.fromTop][coordinates.fromLeft] == SurfaceSquare::obstacle;
}

Planet::Planet(const StartupConfigs& startupConfig)
{
    createSurface(startupConfig.planet);
    createObstacles(startupConfig);
}

Planet::Planet(){};
