#include <vector>
#include <stdexcept>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/simulation/directions.hpp"
#include "../../src/simulation/robot.hpp"
#include "../../src/simulation/i_planet.hpp"
#include "../../src/simulation/planet.hpp"
#include "../../src/simulation/spatial-awareness.hpp"

TEST_CASE("SpatialAwareness turns left")
{
    int robotFromTop = 1;
    int robotFromLeft = 1;
    Coordinates coordinates = { robotFromLeft, robotFromLeft };
    Direction directionFacing = Direction::north;
    SpatialAwareness spatialAwareness = SpatialAwareness(std::move(directionFacing), std::move(coordinates));

    spatialAwareness.turnLeft();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::west);
    spatialAwareness.turnLeft();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::south);
    spatialAwareness.turnLeft();
    REQUIRE(spatialAwareness.getDirectionFacing() ==  Direction::east);
    spatialAwareness.turnLeft();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::north);
}

TEST_CASE("SpatialAwareness turns right")
{
    int robotFromTop = 1;
    int robotFromLeft = 1;
    Coordinates coordinates = { robotFromLeft, robotFromLeft };
    Direction directionFacing = Direction::north;
    SpatialAwareness spatialAwareness = SpatialAwareness(std::move(directionFacing), std::move(coordinates));

    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::east);
    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::south);
    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::west);
    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::north);
}
