#include <sstream>
#include <stdexcept>
#include "surface-factory.hpp"
#include "surface-square.hpp"
#include "../configs/planet-config.hpp"

std::vector<std::vector<SurfaceSquare>> SurfaceFactory::createSurface(const PlanetConfig& planetConfig)
{
    std::vector<std::vector<SurfaceSquare>> surface;
    for(int i = 0; i < planetConfig.surfaceHeight; i++)
    {
        std::vector<SurfaceSquare> sliceOfSurfaceSpanningWidthOfPlanet;
        for(int j = 0; j < planetConfig.surfaceWidth; j++)
        {
            sliceOfSurfaceSpanningWidthOfPlanet.push_back(SurfaceSquare::null);
        }
        surface.push_back(sliceOfSurfaceSpanningWidthOfPlanet);
    }
    return surface;
};

std::vector<std::vector<SurfaceSquare>> SurfaceFactory::createObstacles(const StartupConfigs& startupConfig,
    std::vector<std::vector<SurfaceSquare>> surface)
{
    int numberOfObstacles = 0;
    while(numberOfObstacles < startupConfig.planet.obstacleNumber)
    {
        Coordinates obstacleCoordinates;
        obstacleCoordinates.fromTop = rand() % startupConfig.planet.surfaceHeight;
        obstacleCoordinates.fromLeft = rand() % startupConfig.planet.surfaceWidth;
        //TODO - Replace loop with a randomised list, pop off end (gauranteed to halt in n loops)
        if(surface[obstacleCoordinates.fromTop][obstacleCoordinates.fromLeft] != SurfaceSquare::obstacle
            && !obstacleCoordinates.isSame(startupConfig.robot.coordinates))
        {
            surface[obstacleCoordinates.fromTop][obstacleCoordinates.fromLeft] = SurfaceSquare::obstacle;
            numberOfObstacles++;
        }
    }
    return surface;
};

std::vector<std::vector<SurfaceSquare>> SurfaceFactory::createSurfaceWithObstacles(const StartupConfigs& startupConfig)
{
    std::vector<std::vector<SurfaceSquare>> surface = SurfaceFactory::createSurface(startupConfig.planet);
    return SurfaceFactory::createObstacles(startupConfig, surface);
}
