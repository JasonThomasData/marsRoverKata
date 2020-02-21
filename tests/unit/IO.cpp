#include <iostream>
#include "../../lib/catch.hpp"
#include "../../src/io.hpp"
#include "../../src/configs/startup-config.hpp"

TEST_CASE("argv converted to int" )
{
    std::string argIsDigit = "32";
    std::string argIsNotDigit = "a";
    REQUIRE(IO::getNumericArgument(argIsDigit) == 32);
    REQUIRE_THROWS_AS(IO::getNumericArgument(argIsNotDigit), std::invalid_argument);
}

TEST_CASE("Upper case string to lower case" )
{
    std::string arg = "UPPERCASE STRING";
    REQUIRE(IO::toLowercaseString(arg) == "uppercase string");
}

TEST_CASE("No args" )
{
    int argc = 1;
    char* argv[] = { "./bin/program" };
    REQUIRE_THROWS_AS(IO::getStartupConfigs(argc, argv), std::invalid_argument);
}

TEST_CASE("Not enough args" )
{
    int argc = 2;
    char* argv[] = { "./bin/program", "12" };
    REQUIRE_THROWS_AS(IO::getStartupConfigs(argc, argv), std::invalid_argument);
}

TEST_CASE("argv received, and an appropriate StartupConfigs struct is returned" )
{
    int argc = 7;
    char* argv[] = { "./bin/program", "12", "10", "5", "5", "4", "north" };
    StartupConfigs configs = IO::getStartupConfigs(argc, argv);
    REQUIRE(configs.planet.surfaceWidth == 12);
    REQUIRE(configs.planet.surfaceHeight == 10);
    REQUIRE(configs.planet.obstacleNumber == 5);
    REQUIRE(configs.robot.coordinates.fromTop == 5);
    REQUIRE(configs.robot.coordinates.fromLeft == 4);
    REQUIRE(configs.robot.direction == Direction::north);
}

TEST_CASE("argv has a wrong type, error thrown" )
{
    int argc = 7;
    char* argv[] = { "./bin/program", "12", "10", "v", "5", "4", "north" };
    REQUIRE_THROWS_AS(IO::getStartupConfigs(argc, argv), std::invalid_argument);
}

TEST_CASE("argv has args with negative numbers" )
{
    int argc = 7;
    char* argv[] = { "./bin/program", "-12", "10", "-1", "5", "4", "north" };
    REQUIRE_THROWS_AS(IO::getStartupConfigs(argc, argv), std::invalid_argument);
}

TEST_CASE("argv has an invalid direction" )
{
    int argc = 7;
    char* argv[] = { "./bin/program", "12", "10", "5", "5", "4", "over-there" };
    REQUIRE_THROWS_AS(IO::getStartupConfigs(argc, argv), std::invalid_argument);
}
