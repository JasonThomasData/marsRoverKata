#include <iostream>
#include "../../lib/catch.hpp"
#include "../../src/IO.hpp"

TEST_CASE("argv converted to int" )
{
    std::string argIsDigit = "32";
    std::string argIsNotDigit = "a";
    REQUIRE(IO::getNumericArgument(argIsDigit) == 32);
    REQUIRE_THROWS_AS(IO::getNumericArgument(argIsNotDigit), std::invalid_argument);
}

TEST_CASE("argv received, and an appropriate StartupConfigs struct is returned" )
{
    char* argv[] = { "./bin/program", "12", "10", "5", "5", "4" };
    StartupConfigs configs = IO::getStartupConfigs(argv);
    REQUIRE(configs.planet.surfaceWidth == 12);
    REQUIRE(configs.planet.surfaceHeight == 10);
    REQUIRE(configs.planet.obstacleNumber == 5);
    REQUIRE(configs.robot.x_coordinate == 5);
    REQUIRE(configs.robot.y_coordinate == 4);
}

TEST_CASE("argv has a wrong type, error thrown" )
{
    char* argv[] = { "./bin/program", "12", "10", "v", "5", "4" };
    REQUIRE_THROWS_AS(IO::getStartupConfigs(argv), std::invalid_argument);
}

TEST_CASE("argv has args with negative numbers" )
{
    char* argv[] = { "./bin/program", "-12", "10", "-1", "5", "4" };
    REQUIRE_THROWS_AS(IO::getStartupConfigs(argv), std::invalid_argument);
}
