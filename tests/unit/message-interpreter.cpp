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

SCENARIO( "MessageInterpreter can reject blank maps" )
{
    GIVEN( "Maps are initialised" )
    {
        std::map<const char, Movement> instructionsToMovements = {
            { 'f', Movement::forward },
            { 'b', Movement::backward },
            { 'l', Movement::left },
            { 'r', Movement::right }
        };
        std::map<Movement, const std::string> movementsToReadableInstrunctions = {
            { Movement::forward, "f (forward)" },
            { Movement::backward, "b (backward)" },
            { Movement::left, "l (left)" },
            { Movement::right, "r (right)" }
        };
        std::map<Direction, const std::string> directionToReadableDirection = {
            { Direction::north, "north" },
            { Direction::east, "east" },
            { Direction::south, "south" },
            { Direction::west, "west" }
        };
    
        WHEN( "InstructionsToMovements without data" )
        {
            std::map<const char, Movement> blankInstructionsToMovements;
            THEN( "MessageInterpreter won't construct" )
            {
                REQUIRE_THROWS_AS(
                    MessageInterpreter(std::move(blankInstructionsToMovements),
                        std::move(movementsToReadableInstrunctions),
                        std::move(directionToReadableDirection)),
                    std::invalid_argument);
            }
        }

        WHEN( "MovementsToReadableInstructions without data" )
        {
            std::map<Movement, const std::string> blankMovementsToReadableInstrunctions;
            THEN( "MessageInterpreter won't construct" )
            {
                REQUIRE_THROWS_AS(
                    MessageInterpreter(std::move(instructionsToMovements),
                        std::move(blankMovementsToReadableInstrunctions),
                        std::move(directionToReadableDirection)),
                    std::invalid_argument);
            }
        }

        WHEN( "DirectionToReadableDirection without data" )
        {
            std::map<Direction, const std::string> blankDirectionToReadableDirection;
            THEN( "MessageInterpreter won't construct" )
            {
                REQUIRE_THROWS_AS(
                    MessageInterpreter(std::move(instructionsToMovements),
                        std::move(movementsToReadableInstrunctions),
                        std::move(blankDirectionToReadableDirection)),
                    std::invalid_argument);
            }
        }
    }
}

SCENARIO( "MessageInterpreter can receives instructions" )
{
    GIVEN( "Instructions and movements mapped" )
    {
        std::map<const char, Movement> instructionsToMovements = {
            { 'f', Movement::forward },
            { 'b', Movement::backward },
            { 'l', Movement::left },
            { 'r', Movement::right }
        };
        std::map<Movement, const std::string> movementsToReadableInstrunctions = {
            { Movement::forward, "f (forward)" },
            { Movement::backward, "b (backward)" },
            { Movement::left, "l (left)" },
            { Movement::right, "r (right)" }
        };
        std::map<Direction, const std::string> directionToReadableDirection = {
            { Direction::north, "north" },
            { Direction::east, "east" },
            { Direction::south, "south" },
            { Direction::west, "west" }
        };
        MessageInterpreter messageInterpreter = MessageInterpreter(std::move(instructionsToMovements),
            std::move(movementsToReadableInstrunctions),
            std::move(directionToReadableDirection));

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
