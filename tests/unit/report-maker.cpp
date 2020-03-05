#include <vector>
#include <stdexcept>
#include <iostream>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/directions.hpp"
#include "../../src/robot/robot.hpp"
#include "../../src/robot/spatial-awareness.hpp"
#include "../../src/robot/message-interpreter.hpp"
#include "../../src/robot/report-maker.hpp"
#include "../../src/planet/i_planet.hpp"
#include "../../src/planet/planet.hpp"
#include "../../src/coordinates.hpp"

SCENARIO( "Report maker can return human-readable text streams" )
{
    GIVEN( "Report maker instantiated" )
    {
        RobotConfig robotConfig = RobotConfig();
        ReportMaker reportMaker = ReportMaker(std::move(robotConfig.movementsToReadableInstrunctions),
            std::move(robotConfig.directionToReadableDirection));

        WHEN( "provided with data" )
        {
            Coordinates coordinates = { 2, 3 };
            Direction directionFacing = Direction::east;
            Movement movement = Movement::left;
            THEN( "returns expected collision report" )
            {
                std::string coordinatesSubString = "{ fromTop: 2, fromLeft: 3 }";
                std::string noMovementSubString = "Did not complete move";
                std::string report = reportMaker.makeCollisionReport(coordinates);
                REQUIRE(report.find(coordinatesSubString) != std::string::npos);
                REQUIRE(report.find(noMovementSubString) != std::string::npos);
            }
            THEN( "returns expected movement report" )
            {
                std::string subString = "{ l (left) }";
                std::string report = reportMaker.makeMovementInstructionReport(movement);
                REQUIRE(report.find(subString) != std::string::npos);
            }
            THEN( "returns expected new coordinates report" )
            {
                std::string subString = "{ fromTop: 2, fromLeft: 3 }";
                std::string report = reportMaker.makeNewCoordinatesReport(coordinates);
                REQUIRE(report.find(subString) != std::string::npos);
            }
            THEN( "returns expected turn report" )
            {
                std::string movementSubString = "{ l (left) }";
                std::string directionSubString = "{ east }";
                std::string report = reportMaker.makeTurnReport(directionFacing, movement);
                REQUIRE(report.find(movementSubString) != std::string::npos);
                REQUIRE(report.find(directionSubString) != std::string::npos);
            }
        }
    }
}
