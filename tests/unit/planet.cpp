#include <vector>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/planet/planet.hpp"
#include "../../src/coordinates.hpp"
#include "../../src/directions.hpp"

TEST_CASE("Planet constructs successfully")
{
    //Arrange
    int surfaceWidth = 2;
    int surfaceHeight = 2;
    int obstacleNumber = 3;
    int robotFromTop = 1;
    int robotFromLeft = 1;
    Direction robotDirection = Direction::west;

    StartupConfigs startupConfigs = {
        { surfaceWidth, surfaceHeight, obstacleNumber },
        { { robotFromTop, robotFromLeft } , robotDirection }
    };

    //Act
    Planet planet = Planet(startupConfigs);

    //Assert
    Coordinates obstacleLocation1 = {0, 0};
    Coordinates obstacleLocation2 = {0, 1};
    Coordinates obstacleLocation3 = {1, 0};

    REQUIRE(planet.isObstacleAtCoordinate(obstacleLocation1) == true);
    REQUIRE(planet.isObstacleAtCoordinate(obstacleLocation2) == true);
    REQUIRE(planet.isObstacleAtCoordinate(obstacleLocation3) == true);
    REQUIRE(planet.isObstacleAtCoordinate(startupConfigs.robot.coordinates) == false);
}
