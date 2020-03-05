#include <sstream>
#include <stdexcept>
#include "planet.hpp"
#include "surface-square.hpp"
#include "../configs/planet-config.hpp"

Coordinates Planet::adjustCoordinatesForSurfaceBoundaries(const Coordinates coordinates)
{
    Coordinates adjustedCoordinates;
    if(coordinates.fromTop < surfaceNorthBoundary)
    {
        adjustedCoordinates = { surfaceSouthBoundary, coordinates.fromLeft };
    }
    else if(coordinates.fromTop > surfaceSouthBoundary)
    {
        adjustedCoordinates = { surfaceNorthBoundary, coordinates.fromLeft };
    }
    else if(coordinates.fromLeft > surfaceEastBoundary)
    {
        adjustedCoordinates = { coordinates.fromTop, surfaceWestBoundary };
    }
    else if(coordinates.fromLeft < surfaceWestBoundary)
    {
        adjustedCoordinates = { coordinates.fromTop, surfaceEastBoundary };
    }
    else
    {
        adjustedCoordinates = { coordinates.fromTop, coordinates.fromLeft };
    }
    return adjustedCoordinates;
}

bool Planet::isObstacleAtCoordinate(const Coordinates coordinates)
{
    return surface[coordinates.fromTop][coordinates.fromLeft] == SurfaceSquare::obstacle;
}

Planet::Planet(const std::vector<std::vector<SurfaceSquare>> surface, const PlanetConfig& planetConfig)
    :surface(std::move(surface))
{
    surfaceNorthBoundary = 0;
    surfaceEastBoundary = planetConfig.surfaceWidth - 1; 
    surfaceSouthBoundary = planetConfig.surfaceHeight - 1; 
    surfaceWestBoundary = 0;
}
