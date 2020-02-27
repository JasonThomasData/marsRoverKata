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
