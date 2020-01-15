#include "planet.hpp"
#include "../configs/planet-config.hpp"

void Planet::CreateSurface(PlanetConfig planetConfig)
{};

void Planet::CreateObstacles(PlanetConfig planetConfig)
{};

Planet::Planet(PlanetConfig planetConfig)
{
    CreateSurface(planetConfig);
    CreateObstacles(planetConfig);
}
