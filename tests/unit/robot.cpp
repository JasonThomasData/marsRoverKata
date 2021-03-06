#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
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


SCENARIO( "Robot receives instructions and can move about" )
{
    GIVEN( "Robot has valid configurations")
    {
        int surfaceWidth = 4; 
        int surfaceHeight = 4; 
        int obstacleNumber = 4; //Ignored
        int robotFromTop = 3;
        int robotFromLeft = 0;
        Direction robotDirection = Direction::south;
        Coordinates coordinates = { robotFromTop, robotFromLeft };
        const StartupConfigs startupConfigs = {
            { surfaceWidth, surfaceHeight, obstacleNumber },
            { coordinates, robotDirection }
        };
        std::vector<std::vector<SurfaceSquare>> surface = {
            { SurfaceSquare::null, SurfaceSquare::obstacle, SurfaceSquare::null, SurfaceSquare::null },
            { SurfaceSquare::obstacle, SurfaceSquare::null, SurfaceSquare::null, SurfaceSquare::null },
            { SurfaceSquare::null, SurfaceSquare::null, SurfaceSquare::obstacle, SurfaceSquare::null },
            { SurfaceSquare::null, SurfaceSquare::obstacle, SurfaceSquare::null, SurfaceSquare::null },
        };
        std::unique_ptr<IPlanet> planet = std::make_unique<Planet>(std::move(surface), startupConfigs.planet);
        std::unique_ptr<ISpatialAwareness> spatialAwareness = std::make_unique<SpatialAwareness>(
            robotDirection,
            coordinates,
            startupConfigs.robot.coordinateChangeMoveForward,
            startupConfigs.robot.coordinateChangeMoveBackward);
        std::unique_ptr<IMessageInterpreter> messageInterpreter = std::make_unique<MessageInterpreter>(
            std::move(startupConfigs.robot.instructionsToMovements));
        std::unique_ptr<IReportMaker> reportMaker = std::make_unique<ReportMaker>(
            std::move(startupConfigs.robot.movementsToReadableInstrunctions),
            std::move(startupConfigs.robot.directionToReadableDirection));

        Robot robot = Robot(
            std::move(planet),
            std::move(spatialAwareness),
            std::move(messageInterpreter),
            std::move(reportMaker));

        WHEN( "Robot receives instructions" )
        {
            std::string robotMoveReport = robot.receiveInstructions("fblf");
            THEN( "Robot moves about until it hist obstacle, and returns its report" )
            {
                std::stringstream expectedReport;
                expectedReport<< "Received instruction to move { f (forward) }\n";
                expectedReport<< "Moved to { fromTop: 0, fromLeft: 0 }\n";
                expectedReport<< "Received instruction to move { b (backward) }\n";
                expectedReport<< "Moved to { fromTop: 3, fromLeft: 0 }\n";
                expectedReport<< "Received instruction to move { l (left) }\n";
                expectedReport<< "Turned { l (left) } and is now facing { east }\n";
                expectedReport<< "Received instruction to move { f (forward) }\n";
                expectedReport<< "Hit obstacle at { fromTop: 3, fromLeft: 1 }\n";
                expectedReport<< "Did not complete move\n";
                REQUIRE( expectedReport.str() == robotMoveReport);
            }
        }
    }
}
