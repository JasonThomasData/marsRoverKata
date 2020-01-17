#include <vector>
#include "../../lib/catch.hpp"
#include "../../src/configs/planet-config.hpp"
#include "../../src/simulation/planet.hpp"
#include "../../src/simulation/surface-square.hpp"
#include "../../src/simulation/coordinates.hpp"

TEST_CASE("Constructs successfully")
{
    int surfaceWidth = 14;
    int surfaceHeight = 3;
    int obstacleNumber = 5;
    int robotFromTop = 1;
    int robotFromRight = 1;

    StartupConfigs startupConfigs;
    startupConfigs.planet = { surfaceWidth, surfaceHeight, obstacleNumber };
    startupConfigs.robot.coordinates = { robotFromTop, robotFromRight };
    Planet planet = Planet(startupConfigs);
    int countOfObstaclesOnSurface = planet.countObstaclesOnSurface();

    REQUIRE(countOfObstaclesOnSurface == obstacleNumber);
}

TEST_CASE("Not enough space for obstacles")
{
    int surfaceWidth = 2;
    int surfaceHeight = 3;
    int obstacleNumber = 7;

    StartupConfigs startupConfigs;
    startupConfigs.planet = { surfaceWidth, surfaceHeight, obstacleNumber };

    REQUIRE_THROWS_AS(Planet(startupConfigs), std::invalid_argument);
}

TEST_CASE("Checks obstacles are found")
{
    int surfaceWidth = 2;
    int surfaceHeight = 2;
    int obstacleNumber = 3;

    Coordinates obstacleLocation1 = {0, 0};
    Coordinates obstacleLocation2 = {0, 1};
    Coordinates obstacleLocation3 = {1, 0};
    int robotFromTop = 1;
    int robotFromRight = 1;

    StartupConfigs startupConfigs;
    startupConfigs.planet = { surfaceWidth, surfaceHeight, obstacleNumber };
    startupConfigs.robot.coordinates = { robotFromTop, robotFromRight };
    Planet planet = Planet(startupConfigs);

    REQUIRE(planet.isObstacleAtCoordinate(obstacleLocation1) == true);
    REQUIRE(planet.isObstacleAtCoordinate(obstacleLocation2) == true);
    REQUIRE(planet.isObstacleAtCoordinate(obstacleLocation3) == true);
    REQUIRE(planet.isObstacleAtCoordinate(startupConfigs.robot.coordinates) == false);
}