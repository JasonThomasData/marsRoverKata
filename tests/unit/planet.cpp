#include <vector>
#include "../../lib/catch.hpp"
#include "../../src/configs/planet-config.hpp"
#include "../../src/simulation/planet.hpp"
#include "../../src/simulation/surface.hpp"

TEST_CASE("Constructs successfully")
{
    int surfaceWidth = 3;
    int surfaceHeight = 3;
    int obstacleNumber = 3;
    PlanetConfig planetConfig = { surfaceWidth, surfaceHeight, obstacleNumber };
    Planet planet = Planet(planetConfig);

    REQUIRE(planet.surface.size() == 3);
    REQUIRE(planet.surface.at(0).size() == 3);
    REQUIRE(planet.surface.at(1).size() == 3);
    REQUIRE(planet.surface.at(2).size() == 3);
}

TEST_CASE("")
{
    REQUIRE(true);
    //REQUIRE_THROWS_AS(IO::getStartupConfigs(argc, argv), std::invalid_argument);
}
