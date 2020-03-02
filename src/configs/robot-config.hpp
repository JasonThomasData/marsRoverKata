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
    const std::map<const char, Movement> instructionsToMovements = {
        { 'f', Movement::forward },
        { 'b', Movement::backward },
        { 'l', Movement::left },
        { 'r', Movement::right }
    };
    const std::map<const Movement, std::string> movementsToReadableInstrunctions = {
        { Movement::forward, "f (forward)" },
        { Movement::backward, "b (backward)" },
        { Movement::left, "l (left)" },
        { Movement::right, "r (right)" }
    };
    const std::map<const Direction, std::string> directionToReadableDirection = {
        { Direction::north, "north" },
        { Direction::east, "east" },
        { Direction::south, "south" },
        { Direction::west, "west" }
    };
    const std::map<const Direction, Coordinates> coordinateChangeMoveForward = {
        { Direction::north, { -1, 0 } },
        { Direction::east, { 0, 1 } },
        { Direction::south, { 1, 0 } },
        { Direction::west, { 0, -1 } }
    };
    const std::map<const Direction, Coordinates> coordinateChangeMoveBackward = {
        { Direction::north, { 1, 0 } },
        { Direction::east, { 0, -1 } },
        { Direction::south, { -1, 0 } },
        { Direction::west, { 0, 1 } }
    };
};

#endif
