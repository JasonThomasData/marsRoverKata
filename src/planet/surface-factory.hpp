#include <vector>
#include "../configs/planet-config.hpp"
#include "../configs/startup-config.hpp"
#include "surface-square.hpp"

#ifndef SurfaceFactory_h 
#define SurfaceFactory_h

namespace SurfaceFactory
{
    std::vector<std::vector<SurfaceSquare>> createSurface(const PlanetConfig& planetConfig);
    std::vector<Coordinates> getObstacleCoordinates(const PlanetConfig& planetConfig);
    std::vector<std::vector<SurfaceSquare>> addObstaclesToSurface(const StartupConfigs& startupConfig,
        std::vector<std::vector<SurfaceSquare>>& surfaceWithoutObstacles);
    std::vector<std::vector<SurfaceSquare>> createSurfaceWithObstacles(const StartupConfigs& startupConfig);
};

#endif
