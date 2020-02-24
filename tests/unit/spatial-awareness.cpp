#include <vector>
#include <stdexcept>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/simulation/directions.hpp"
#include "../../src/simulation/robot.hpp"
#include "../../src/simulation/i_planet.hpp"
#include "../../src/simulation/planet.hpp"
#include "../../src/simulation/spatial-awareness.hpp"

class TestFixtures 
{
    private:
        int robotFromTop = 3;
        int robotFromLeft = 3;
    public:
        Coordinates coordinates = { robotFromTop, robotFromLeft };
        Direction directionFacing = Direction::north;
};

/* 
TEST_CASE("SpatialAwareness turns left")
{
    TestFixtures fixtures = TestFixtures();
    SpatialAwareness spatialAwareness = SpatialAwareness(std::move(fixtures.directionFacing), std::move(fixtures.coordinates));

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
    SpatialAwareness spatialAwareness = SpatialAwareness(std::move(fixtures.directionFacing), std::move(fixtures.coordinates));

    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::east);
    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::south);
    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::west);
    spatialAwareness.turnRight();
    REQUIRE(spatialAwareness.getDirectionFacing() == Direction::north);
}

*/

bool TestSpatialAwarenessReturnsNextCoordinates(Movement movement, Direction directionFacing, Coordinates expectedNextCoordinates)
{
    TestFixtures fixtures = TestFixtures();
    SpatialAwareness spatialAwareness = SpatialAwareness(std::move(directionFacing), std::move(fixtures.coordinates));
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