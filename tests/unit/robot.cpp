#include <vector>
#include <stdexcept>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/directions.hpp"
#include "../../src/robot/robot.hpp"
#include "../../src/robot/spatial-awareness.hpp"
#include "../../src/planet/i_planet.hpp"
#include "../../src/planet/planet.hpp"
#include "../../src/coordinates.hpp"

class TestFixtures 
{
    private:
        int surfaceWidth = 14;
        int surfaceHeight = 3;
        int obstacleNumber = 5;
        int robotFromTop = 1;
        int robotFromLeft = 1;
        Direction robotDirection = Direction::south;
        Coordinates coordinates = { robotFromTop, robotFromLeft };
        const StartupConfigs startupConfigs = {
            { surfaceWidth, surfaceHeight, obstacleNumber },
            { coordinates, robotDirection }
        };
    public:
        std::unique_ptr<IPlanet> planet = std::make_unique<Planet>(startupConfigs);
        std::unique_ptr<ISpatialAwareness> spatialAwareness = std::make_unique<SpatialAwareness>(
            robotDirection,
            coordinates,
            startupConfigs.robot.coordinateChangeMoveForward,
            startupConfigs.robot.coordinateChangeMoveBackward);
        std::map<const char, Movement> instructionsToMovements = {
            { 'f', Movement::forward },
            { 'b', Movement::backward },
            { 'l', Movement::left },
            { 'r', Movement::right }
        };
};

TEST_CASE("Robot can receive valid instuctions")
{
    TestFixtures fixtures = TestFixtures();
    std::map<const char, Movement> instructionsToMovements = {
        { 'f', Movement::forward },
        { 'b', Movement::backward },
        { 'l', Movement::left },
        { 'r', Movement::right },
    };

    Robot robot = Robot(std::move(fixtures.planet),
        std::move(fixtures.spatialAwareness),
        std::move(instructionsToMovements));

    REQUIRE_NOTHROW(robot.interpretInstructions("flbr"));
}

TEST_CASE("Robot rejects invalid instuctions")
{
    TestFixtures fixtures = TestFixtures();
    std::map<const char, Movement> instructionsToMovements = {
        { 'f', Movement::forward },
        { 'b', Movement::backward },
        { 'l', Movement::left },
        { 'r', Movement::right },
    };

    Robot robot = Robot(std::move(fixtures.planet),
        std::move(fixtures.spatialAwareness),
        std::move(instructionsToMovements));

    REQUIRE_THROWS_AS(robot.interpretInstructions(""), std::invalid_argument);
    REQUIRE_THROWS_AS(robot.interpretInstructions("fl.br"), std::invalid_argument);
    REQUIRE_THROWS_AS(robot.interpretInstructions("1flbr"), std::invalid_argument);
}

TEST_CASE("Robot can understand instructions to translate to movements")
{
    TestFixtures fixtures = TestFixtures();
    std::map<const char, Movement> instructionsToMovements = {
        { 'f', Movement::forward },
        { 'b', Movement::backward },
        { 'l', Movement::left },
        { 'r', Movement::right },
    };

    Robot robot = Robot(std::move(fixtures.planet),
        std::move(fixtures.spatialAwareness),
        std::move(instructionsToMovements));

    std::vector<Movement> translatedMovements = robot.interpretInstructions("flbr");

    REQUIRE(translatedMovements.at(0) == Movement::forward);
    REQUIRE(translatedMovements.at(1) == Movement::left);
    REQUIRE(translatedMovements.at(2) == Movement::backward);
    REQUIRE(translatedMovements.at(3) == Movement::right);
}

TEST_CASE("Robot requires map initialised not in a struct")
{
    TestFixtures fixtures = TestFixtures();

    //Seems to be a bug with Catch, 
    REQUIRE_THROWS_AS(
        Robot(std::move(fixtures.planet),
            std::move(fixtures.spatialAwareness),
            std::move(fixtures.instructionsToMovements)),
        std::invalid_argument);

    std::map<const char, Movement> instructionsToMovements = {
        { 'f', Movement::forward },
        { 'b', Movement::backward },
        { 'l', Movement::left },
        { 'r', Movement::right }
    };
    REQUIRE_NOTHROW(
        Robot(std::move(fixtures.planet),
            std::move(fixtures.spatialAwareness),
            std::move(instructionsToMovements)));
}