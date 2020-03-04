#include <vector>
#include <stdexcept>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/directions.hpp"
#include "../../src/robot/robot.hpp"
#include "../../src/robot/spatial-awareness.hpp"
#include "../../src/robot/message-interpreter.hpp"
#include "../../src/planet/i_planet.hpp"
#include "../../src/planet/planet.hpp"
#include "../../src/coordinates.hpp"

SCENARIO( "MessageInterpreter can receives instructions" )
{
    GIVEN( "Instructions and movements mapped" )
    {
        RobotConfig robotConfig = RobotConfig();
        MessageInterpreter messageInterpreter = MessageInterpreter(
            std::move(robotConfig.instructionsToMovements),
            std::move(robotConfig.movementsToReadableInstrunctions),
            std::move(robotConfig.directionToReadableDirection));

        THEN( "can receive valid instructions" )
        {
            REQUIRE_NOTHROW(messageInterpreter.interpretInstructions("flbr"));
        }

        THEN( "can reject invalid instructions" )
        {
            REQUIRE_THROWS_AS(messageInterpreter.interpretInstructions(""), std::invalid_argument);
            REQUIRE_THROWS_AS(messageInterpreter.interpretInstructions("fl.br"), std::invalid_argument);
            REQUIRE_THROWS_AS(messageInterpreter.interpretInstructions("1flbr"), std::invalid_argument);
        }

        WHEN( "receives valid instructions" )
        {
            std::vector<Movement> translatedMovements = messageInterpreter.interpretInstructions("flbr");
            THEN( "an appropriate vector of movements is received" )
            {
                REQUIRE(translatedMovements.at(0) == Movement::forward);
                REQUIRE(translatedMovements.at(1) == Movement::left);
                REQUIRE(translatedMovements.at(2) == Movement::backward);
                REQUIRE(translatedMovements.at(3) == Movement::right);
            }
        }

        THEN( "can retrieve readable message for a movement" )
        {
            REQUIRE( messageInterpreter.getReadableInstruction(Movement::forward) == "f (forward)" );
            REQUIRE( messageInterpreter.getReadableInstruction(Movement::backward) == "b (backward)" );
            REQUIRE( messageInterpreter.getReadableInstruction(Movement::left) == "l (left)" );
            REQUIRE( messageInterpreter.getReadableInstruction(Movement::right) == "r (right)" );
        }

        THEN( "can retrieve readable message for a direction" )
        {
            REQUIRE( messageInterpreter.getReadableDirection(Direction::north) == "north" );
            REQUIRE( messageInterpreter.getReadableDirection(Direction::east) == "east" );
            REQUIRE( messageInterpreter.getReadableDirection(Direction::south) == "south" );
            REQUIRE( messageInterpreter.getReadableDirection(Direction::west) == "west" );
        }
    }
}
