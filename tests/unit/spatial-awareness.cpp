#include <vector>
#include <stdexcept>
#include <iostream>
#include "../../lib/catch.hpp"
#include "../../src/configs/robot-config.hpp"
#include "../../src/directions.hpp"
#include "../../src/robot/robot.hpp"
#include "../../src/robot/spatial-awareness.hpp"
#include "../../src/planet/i_planet.hpp"
#include "../../src/planet/planet.hpp"

SCENARIO( "SpatialAwareness can receive movement orders and perform movements" )
{
    GIVEN( "Coordinates set")
    {
        int robotFromTop = 3;
        int robotFromLeft = 3;
        RobotConfig robotConfig = RobotConfig();
        robotConfig.coordinates = { robotFromTop, robotFromLeft };
        GIVEN( "Facing north ")
        {
            SpatialAwareness spatialAwareness = SpatialAwareness(
                std::move(Direction::north),
                std::move(robotConfig.coordinates),
                std::move(robotConfig.coordinateChangeMoveForward),
                std::move(robotConfig.coordinateChangeMoveBackward));
            WHEN( " SpatialAwareness turns left " )
            {
                spatialAwareness.turnLeft();
                THEN( "Is facing west" )
                {
                    REQUIRE( spatialAwareness.getDirectionFacing() == Direction::west );
                }
            }
            WHEN( " SpatialAwareness turns right " )
            {
                spatialAwareness.turnRight();
                THEN( "Is facing east" )
                {
                    REQUIRE( spatialAwareness.getDirectionFacing() == Direction::east );
                }
            }
            WHEN( " SpatialAwareness receives move forward instructon " )
            {
                Coordinates nextCoordinates = spatialAwareness.getNextCoordinates(Movement::forward);
                THEN( " Coordinates to north received " )
                {
                    Coordinates expectedCoordinates = { 2, 3 };
                    REQUIRE( nextCoordinates.fromTop == expectedCoordinates.fromTop );
                    REQUIRE( nextCoordinates.fromLeft == expectedCoordinates.fromLeft );
                }
            }
            WHEN( " SpatialAwareness receives move backward instructon " )
            {
                Coordinates nextCoordinates = spatialAwareness.getNextCoordinates(Movement::backward);
                THEN( " Coordinates to south received " )
                {
                    Coordinates expectedCoordinates = { 4, 3 };
                    REQUIRE( nextCoordinates.fromTop == expectedCoordinates.fromTop );
                    REQUIRE( nextCoordinates.fromLeft == expectedCoordinates.fromLeft );
                }
            }
        }
        GIVEN( "Facing south ")
        {
            SpatialAwareness spatialAwareness = SpatialAwareness(
                std::move(Direction::south),
                std::move(robotConfig.coordinates),
                std::move(robotConfig.coordinateChangeMoveForward),
                std::move(robotConfig.coordinateChangeMoveBackward));
            WHEN( " SpatialAwareness turns left " )
            {
                spatialAwareness.turnLeft();
                THEN( "Is facing east" )
                {
                    REQUIRE( spatialAwareness.getDirectionFacing() == Direction::east );
                }
            }
            WHEN( " SpatialAwareness turns right " )
            {
                spatialAwareness.turnRight();
                THEN( "Is facing west" )
                {
                    REQUIRE( spatialAwareness.getDirectionFacing() == Direction::west );
                }
            }
            WHEN( " SpatialAwareness receives move forward instructon " )
            {
                Coordinates nextCoordinates = spatialAwareness.getNextCoordinates(Movement::forward);
                THEN( " Coordinates to south received " )
                {
                    Coordinates expectedCoordinates = { 4, 3 };
                    REQUIRE( nextCoordinates.fromTop == expectedCoordinates.fromTop );
                    REQUIRE( nextCoordinates.fromLeft == expectedCoordinates.fromLeft );
                }
            }
            WHEN( " SpatialAwareness receives move backward instructon " )
            {
                Coordinates nextCoordinates = spatialAwareness.getNextCoordinates(Movement::backward);
                THEN( " Coordinates to north received " )
                {
                    Coordinates expectedCoordinates = { 2, 3 };
                    REQUIRE( nextCoordinates.fromTop == expectedCoordinates.fromTop );
                    REQUIRE( nextCoordinates.fromLeft == expectedCoordinates.fromLeft );
                }
            }
        }
        GIVEN( "Facing east ")
        {
            SpatialAwareness spatialAwareness = SpatialAwareness(
                std::move(Direction::east),
                std::move(robotConfig.coordinates),
                std::move(robotConfig.coordinateChangeMoveForward),
                std::move(robotConfig.coordinateChangeMoveBackward));
            WHEN( " SpatialAwareness turns left " )
            {
                spatialAwareness.turnLeft();
                THEN( "Is facing north" )
                {
                    REQUIRE( spatialAwareness.getDirectionFacing() == Direction::north );
                }
            }
            WHEN( " SpatialAwareness turns right " )
            {
                spatialAwareness.turnRight();
                THEN( "Is facing south" )
                {
                    REQUIRE( spatialAwareness.getDirectionFacing() == Direction::south );
                }
            }
            WHEN( " SpatialAwareness receives move forward instructon " )
            {
                Coordinates nextCoordinates = spatialAwareness.getNextCoordinates(Movement::forward);
                THEN( " Coordinates to east received " )
                {
                    Coordinates expectedCoordinates = { 3, 4 };
                    REQUIRE( nextCoordinates.fromTop == expectedCoordinates.fromTop );
                    REQUIRE( nextCoordinates.fromLeft == expectedCoordinates.fromLeft );
                }
            }
            WHEN( " SpatialAwareness receives move backward instructon " )
            {
                Coordinates nextCoordinates = spatialAwareness.getNextCoordinates(Movement::backward);
                THEN( " Coordinates to west received " )
                {
                    Coordinates expectedCoordinates = { 3, 2 };
                    REQUIRE( nextCoordinates.fromTop == expectedCoordinates.fromTop );
                    REQUIRE( nextCoordinates.fromLeft == expectedCoordinates.fromLeft );
                }
            }
        }
        GIVEN( "Facing west ")
        {
            SpatialAwareness spatialAwareness = SpatialAwareness(
                std::move(Direction::west),
                std::move(robotConfig.coordinates),
                std::move(robotConfig.coordinateChangeMoveForward),
                std::move(robotConfig.coordinateChangeMoveBackward));
            WHEN( " SpatialAwareness turns left " )
            {
                spatialAwareness.turnLeft();
                THEN( "Is facing south" )
                {
                    REQUIRE( spatialAwareness.getDirectionFacing() == Direction::south );
                }
            }
            WHEN( " SpatialAwareness turns right " )
            {
                spatialAwareness.turnRight();
                THEN( "Is facing south" )
                {
                    REQUIRE( spatialAwareness.getDirectionFacing() == Direction::north );
                }
            }
            WHEN( " SpatialAwareness receives move forward instructon " )
            {
                Coordinates nextCoordinates = spatialAwareness.getNextCoordinates(Movement::forward);
                THEN( " Coordinates to west received " )
                {
                    Coordinates expectedCoordinates = { 3, 2 };
                    REQUIRE( nextCoordinates.fromTop == expectedCoordinates.fromTop );
                    REQUIRE( nextCoordinates.fromLeft == expectedCoordinates.fromLeft );
                }
            }
            WHEN( " SpatialAwareness receives move backward instructon " )
            {
                Coordinates nextCoordinates = spatialAwareness.getNextCoordinates(Movement::backward);
                THEN( " Coordinates to east received " )
                {
                    Coordinates expectedCoordinates = { 3, 4 };
                    REQUIRE( nextCoordinates.fromTop == expectedCoordinates.fromTop );
                    REQUIRE( nextCoordinates.fromLeft == expectedCoordinates.fromLeft );
                }
            }
        }
    }
}
