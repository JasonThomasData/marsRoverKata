#include <map>

#include "../coordinates.hpp"
#include "../directions.hpp"
#include "../robot/movements.hpp"

#ifndef RobotConfig_hpp
#define RobotConfig_hpp

struct RobotConfig
{
    Coordinates coordinates;
    Direction directionFacing;
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
    std::map<Direction, Coordinates> coordinateChangeMoveForward = {
        { Direction::north, { -1, 0 } },
        { Direction::east, { 0, 1 } },
        { Direction::south, { 1, 0 } },
        { Direction::west, { 0, -1 } }
    };
    std::map<Direction, Coordinates> coordinateChangeMoveBackward = {
        { Direction::north, { 1, 0 } },
        { Direction::east, { 0, -1 } },
        { Direction::south, { -1, 0 } },
        { Direction::west, { 0, 1 } }
    };
};

#endif
