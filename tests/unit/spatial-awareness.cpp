#include <vector>
#include <stdexcept>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/directions.hpp"
#include "../../src/robot/robot.hpp"
#include "../../src/robot/spatial-awareness.hpp"
#include "../../src/planet/i_planet.hpp"
#include "../../src/planet/planet.hpp"

class TestFixtures 
{
    private:
        int robotFromTop = 3;
        int robotFromLeft = 3;
        Coordinates coordinates = { robotFromTop, robotFromLeft };
        Direction directionFacing = Direction::north;
    public:
        RobotConfig robotConfig = { coordinates, directionFacing };
};

TEST_CASE("SpatialAwareness turns left")
{
    TestFixtures fixtures = TestFixtures();
    SpatialAwareness spatialAwareness = SpatialAwareness(
        std::move(fixtures.robotConfig.directionFacing),
        std::move(fixtures.robotConfig.coordinates),
        std::move(fixtures.robotConfig.coordinateChangeMoveForward),
        std::move(fixtures.robotConfig.coordinateChangeMoveBackward));

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
    TestFixtures fixtures = TestFixtures();
    SpatialAwareness spatialAwareness = SpatialAwareness(
        std::move(fixtures.robotConfig.directionFacing),
        std::move(fixtures.robotConfig.coordinates),
        std::move(fixtures.robotConfig.coordinateChangeMoveForward),
        std::move(fixtures.robotConfig.coordinateChangeMoveBackward));

    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::east);
    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::south);
    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::west);
    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::north);
}

bool TestSpatialAwarenessReturnsNextCoordinates(Movement movement, Direction directionFacing, Coordinates expectedNextCoordinates)
{
    TestFixtures fixtures = TestFixtures();
    SpatialAwareness spatialAwareness = SpatialAwareness(
        std::move(directionFacing),
        std::move(fixtures.robotConfig.coordinates),
        std::move(fixtures.robotConfig.coordinateChangeMoveForward),
        std::move(fixtures.robotConfig.coordinateChangeMoveBackward));
    Coordinates nextCoordinates = spatialAwareness.getNextCoordinates(movement);

    return expectedNextCoordinates.fromTop == nextCoordinates.fromTop &&
        expectedNextCoordinates.fromLeft == nextCoordinates.fromLeft;
}

TEST_CASE("SpatialAwareness returns next coordinates")
{
    REQUIRE(TestSpatialAwarenessReturnsNextCoordinates(Movement::forward, Direction::north, { 2, 3 }));
    REQUIRE(TestSpatialAwarenessReturnsNextCoordinates(Movement::forward, Direction::east, { 3, 4 }));
    REQUIRE(TestSpatialAwarenessReturnsNextCoordinates(Movement::forward, Direction::south, { 4, 3 }));
    REQUIRE(TestSpatialAwarenessReturnsNextCoordinates(Movement::forward, Direction::west, { 3, 2 }));
    REQUIRE(TestSpatialAwarenessReturnsNextCoordinates(Movement::backward, Direction::north, { 4, 3 }));
    REQUIRE(TestSpatialAwarenessReturnsNextCoordinates(Movement::backward, Direction::east, { 3, 2 }));
    REQUIRE(TestSpatialAwarenessReturnsNextCoordinates(Movement::backward, Direction::south, { 2, 3 }));
    REQUIRE(TestSpatialAwarenessReturnsNextCoordinates(Movement::backward, Direction::west, { 3, 4 }));
}