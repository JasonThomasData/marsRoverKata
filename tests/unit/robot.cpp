#include <vector>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/simulation/robot.hpp"
#include "../../src/simulation/i_planet.hpp"
#include "../../src/simulation/planet.hpp"

TEST_CASE("Robot constructs successfully")
{
    int surfaceWidth = 14;
    int surfaceHeight = 3;
    int obstacleNumber = 5;
    int robotFromTop = 1;
    int robotFromRight = 1;

    const StartupConfigs startupConfigs = {
        { surfaceWidth, surfaceHeight, obstacleNumber },
        { robotFromTop, robotFromRight }
    };
    std::unique_ptr<IPlanet> planet = std::make_unique<Planet>(startupConfigs);

    REQUIRE_NOTHROW(Robot(std::move(planet), startupConfigs.robot));
}
