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

struct TestFixtures 
{
    std::map<const char, Movement> instructionsToMovements = {
        { 'f', Movement::forward },
        { 'b', Movement::backward },
        { 'l', Movement::left },
        { 'r', Movement::right }
    };
};

TEST_CASE("Message interpreter can receive valid instuctions")
{
    TestFixtures fixtures = TestFixtures();
    MessageInterpreter messageInterpreter = MessageInterpreter(std::move(fixtures.instructionsToMovements));

    REQUIRE_NOTHROW(messageInterpreter.interpretInstructions("flbr"));
}

TEST_CASE("Message interpreter rejects invalid instuctions")
{
    TestFixtures fixtures = TestFixtures();
    MessageInterpreter messageInterpreter = MessageInterpreter(std::move(fixtures.instructionsToMovements));

    REQUIRE_THROWS_AS(messageInterpreter.interpretInstructions(""), std::invalid_argument);
    REQUIRE_THROWS_AS(messageInterpreter.interpretInstructions("fl.br"), std::invalid_argument);
    REQUIRE_THROWS_AS(messageInterpreter.interpretInstructions("1flbr"), std::invalid_argument);
}

TEST_CASE("Message interpreter can understand instructions to translate to movements")
{
    TestFixtures fixtures = TestFixtures();
    MessageInterpreter messageInterpreter = MessageInterpreter(std::move(fixtures.instructionsToMovements));

    std::vector<Movement> translatedMovements = messageInterpreter.interpretInstructions("flbr");

    REQUIRE(translatedMovements.at(0) == Movement::forward);
    REQUIRE(translatedMovements.at(1) == Movement::left);
    REQUIRE(translatedMovements.at(2) == Movement::backward);
    REQUIRE(translatedMovements.at(3) == Movement::right);
}

TEST_CASE("Message interpreter requires map initialised not in a struct")
{
    TestFixtures fixtures = TestFixtures();
    MessageInterpreter messageInterpreter = MessageInterpreter(std::move(fixtures.instructionsToMovements));

    //Seems to be a bug with Catch, 
    REQUIRE_THROWS_AS(
        MessageInterpreter(std::move(fixtures.instructionsToMovements)),
        std::invalid_argument);

    std::map<const char, Movement> instructionsToMovements = {
        { 'f', Movement::forward },
        { 'b', Movement::backward },
        { 'l', Movement::left },
        { 'r', Movement::right }
    };
    REQUIRE_NOTHROW(
        MessageInterpreter(std::move(instructionsToMovements)));
}
