#include "planet.hpp"
#include "../configs/PlanetConfig.hpp"

void Planet::CreateSurface(PlanetConfig planetConfig)
{};

void Planet::CreateObstacles(PlanetConfig planetConfig)
{};

Planet::Planet(PlanetConfig planetConfig)
{
    CreateSurface(planetConfig);
    CreateObstacles(planetConfig);
}
