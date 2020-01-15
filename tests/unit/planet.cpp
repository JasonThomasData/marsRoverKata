#include <vector>
#include "../../lib/catch.hpp"
#include "../../src/configs/planet-config.hpp"
#include "../../src/simulation/planet.hpp"
#include "../../src/simulation/surface-square.hpp"

TEST_CASE("Constructs successfully")
{
    int surfaceWidth = 14;
    int surfaceHeight = 3;
    int obstacleNumber = 5;

    int obstaclesFound = 0;

    PlanetConfig planetConfig = { surfaceWidth, surfaceHeight, obstacleNumber };
    Planet planet = Planet(planetConfig);

    for(int i = 0; i < surfaceHeight; i++)
    {
        for(int j = 0; j < surfaceWidth; j++)
        {
            if(planet.whatIsAtCoordinate(i, j) == SurfaceSquare::obstacle)
            {
                obstaclesFound ++;
            }
        }
    }

    REQUIRE(obstaclesFound == obstacleNumber);
}

TEST_CASE("Not enough space for obstacles")
{
    int surfaceWidth = 2;
    int surfaceHeight = 3;
    int obstacleNumber = 7;

    PlanetConfig planetConfig = { surfaceWidth, surfaceHeight, obstacleNumber };

    REQUIRE_THROWS_AS(Planet(planetConfig), std::invalid_argument);
}
