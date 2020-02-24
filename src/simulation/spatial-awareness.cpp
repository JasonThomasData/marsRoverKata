#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <iostream>
#include "spatial-awareness.hpp"
#include "movements.hpp"
#include "directions.hpp"
#include "coordinates.hpp"

Coordinates SpatialAwareness::getNextCoordinates(Movement movement)
{
    if (movement == Movement::forward)
    {
        Coordinates nextCoordinates = { 0, 0 };
        return nextCoordinates;
    }
    else if (movement == Movement::backward)
    {
        Coordinates nextCoordinates = { 0, 0 };
        return nextCoordinates;
    }
}

Direction SpatialAwareness::getDirectionFacing()
{
    return directionFacing;
}

void SpatialAwareness::turnLeft() {}

void SpatialAwareness::turnRight() {}

SpatialAwareness::SpatialAwareness(Direction directionFacing, Coordinates coordinates)
    :directionFacing(std::move(directionFacing)),
    coordinates(std::move(coordinates))
{};
