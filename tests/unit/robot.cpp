#include <vector>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/simulation/directions.hpp"
#include "../../src/simulation/robot.hpp"
#include "../../src/simulation/i_planet.hpp"
#include "../../src/simulation/planet.hpp"

TEST_CASE("Robot constructs successfully")
{
    //This is repeated elsewhere. Can this be a test fixture?
    int surfaceWidth = 14;
    int surfaceHeight = 3;
    int obstacleNumber = 5;
    int robotFromTop = 1;
    int robotFromLeft = 1;
    Direction robotDirection = Direction::south;
    const StartupConfigs startupConfigs = {
        { surfaceWidth, surfaceHeight, obstacleNumber },
        { { robotFromTop, robotFromLeft }, robotDirection }
    };
    std::unique_ptr<IPlanet> planet = std::make_unique<Planet>(startupConfigs);

    REQUIRE_NOTHROW(Robot(std::move(planet), startupConfigs.robot));
}

TEST_CASE("Robot can receive valid instuctions")
{
    int surfaceWidth = 14;
    int surfaceHeight = 3;
    int obstacleNumber = 5;
    int robotFromTop = 1;
    int robotFromLeft = 1;
    Direction robotDirection = Direction::south;
    const StartupConfigs startupConfigs = {
        { surfaceWidth, surfaceHeight, obstacleNumber },
        { { robotFromTop, robotFromLeft }, robotDirection }
    };
    std::unique_ptr<IPlanet> planet = std::make_unique<Planet>(startupConfigs);
    Robot robot = Robot(std::move(planet), startupConfigs.robot);

    const std::string instructions = "flbr";

    REQUIRE_NOTHROW(robot.interpretAndApplyInstructions(instructions));
}
