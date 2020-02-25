#include <vector>
#include <stdexcept>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/simulation/directions.hpp"
#include "../../src/simulation/robot.hpp"
#include "../../src/simulation/i_planet.hpp"
#include "../../src/simulation/planet.hpp"
#include "../../src/simulation/spatial-awareness.hpp"
#include "../../src/simulation/coordinates.hpp"

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
};

TEST_CASE("Robot can receive valid instuctions")
{
    TestFixtures fixtures = TestFixtures();
    Robot robot = Robot(std::move(fixtures.planet), std::move(fixtures.spatialAwareness));

    const std::string instructions = "flbr";

    REQUIRE_NOTHROW(robot.interpretInstructions(instructions));
}

TEST_CASE("Robot rejects invalid instuctions")
{
    TestFixtures fixtures = TestFixtures();
    Robot robot = Robot(std::move(fixtures.planet), std::move(fixtures.spatialAwareness));

    REQUIRE_THROWS_AS(robot.interpretInstructions(""), std::invalid_argument);
    REQUIRE_THROWS_AS(robot.interpretInstructions("fl.br"), std::invalid_argument);
    REQUIRE_THROWS_AS(robot.interpretInstructions("1flbr"), std::invalid_argument);
}

TEST_CASE("Robot can understand instructions to translate to movements")
{
    TestFixtures fixtures = TestFixtures();
    Robot robot = Robot(std::move(fixtures.planet), std::move(fixtures.spatialAwareness));

    const std::string instructions = "flbr";
    std::vector<Movement> translatedMovements = robot.interpretInstructions(instructions);

    REQUIRE(translatedMovements.at(0) == Movement::forward);
    REQUIRE(translatedMovements.at(1) == Movement::left);
    REQUIRE(translatedMovements.at(2) == Movement::backward);
    REQUIRE(translatedMovements.at(3) == Movement::right);
}
