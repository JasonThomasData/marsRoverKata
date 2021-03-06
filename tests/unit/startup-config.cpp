#include <vector>
#include "../../lib/catch.hpp"
#include "../../src/configs/planet-config.hpp"
#include "../../src/configs/robot-config.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/coordinates.hpp"
#include "../../src/directions.hpp"

TEST_CASE("Configs constructed successfully")
{
    int surfaceWidth = 14;
    int surfaceHeight = 3;
    int obstacleNumber = 5;
    int robotFromTop = 1;
    int robotFromLeft = 1;
    Direction direction = Direction::west;

    PlanetConfig planetConfig = { surfaceWidth, surfaceHeight, obstacleNumber };
    Coordinates coordinates = { robotFromTop, robotFromLeft };
    RobotConfig robotConfig = { coordinates, direction };

    REQUIRE_NOTHROW( StartupConfigs( std::move(planetConfig),
                                   std::move(robotConfig)) );
}

TEST_CASE("Not enough space on surface for obstacles")
{
    int surfaceWidth = 2;
    int surfaceHeight = 3;
    int obstacleNumber = 7;
    int robotFromTop = 1;
    int robotFromLeft = 1;
    Direction direction = Direction::west;

    PlanetConfig planetConfig = { surfaceWidth, surfaceHeight, obstacleNumber };
    Coordinates coordinates = { robotFromTop, robotFromLeft };
    RobotConfig robotConfig = { coordinates, direction };

    REQUIRE_THROWS_AS( StartupConfigs( std::move(planetConfig),
                                   std::move(robotConfig) ),
                       std::invalid_argument );
}

TEST_CASE("Not enough space on surface for robot")
{
    int surfaceWidth = 2;
    int surfaceHeight = 3;
    int obstacleNumber = 6;
    int robotFromTop = 1;
    int robotFromLeft = 1;
    Direction direction = Direction::west;

    PlanetConfig planetConfig = { surfaceWidth, surfaceHeight, obstacleNumber };
    Coordinates coordinates = { robotFromTop, robotFromLeft };
    RobotConfig robotConfig = { coordinates, direction };

    REQUIRE_THROWS_AS( StartupConfigs( std::move(planetConfig),
                                   std::move(robotConfig) ),
                       std::invalid_argument );
}

TEST_CASE("Robot not placed on surface")
{
    int surfaceWidth = 3;
    int surfaceHeight = 3;
    int obstacleNumber = 1;
    int robotFromTop = 10;
    int robotFromLeft = 10;
    Direction direction = Direction::west;

    PlanetConfig planetConfig = { surfaceWidth, surfaceHeight, obstacleNumber };
    Coordinates coordinates = { robotFromTop, robotFromLeft };
    RobotConfig robotConfig = { coordinates, direction };

    REQUIRE_THROWS_AS( StartupConfigs( std::move(planetConfig),
                                   std::move(robotConfig) ),
                       std::invalid_argument );
}
