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
    Coordinates changeInCoordinates = getNextCoordinatesChange(movement);
    return applyChange(coordinates, changeInCoordinates);
}

Coordinates SpatialAwareness::applyChange(Coordinates coordinates, const Coordinates& changeInCoordinates)
{
    coordinates.fromTop += changeInCoordinates.fromTop;
    coordinates.fromLeft += changeInCoordinates.fromLeft;
    return coordinates;
}

Coordinates SpatialAwareness::getNextCoordinatesChange(Movement movement)
{
    //TODO - this seems inefficient, make a map instead
    Coordinates nextCoordinates;
    if (movement == Movement::forward)
    {
        if (directionFacing == Direction::north)
        {
            nextCoordinates = { -1, 0 };
        }
        else if (directionFacing == Direction::east)
        {
            nextCoordinates = { 0, 1 };
        }
        else if (directionFacing == Direction::south)
        {
            nextCoordinates = { 1, 0 };
        }
        else
        {
            nextCoordinates = { 0, -1 };
        }
    }
    else if (movement == Movement::backward)
    {
        if (directionFacing == Direction::north)
        {
            nextCoordinates = { 1, 0 };
        }
        else if (directionFacing == Direction::east)
        {
            nextCoordinates = { 0, -1 };
        }
        else if (directionFacing == Direction::south)
        {
            nextCoordinates = { -1, 0 };
        }
        else
        {
            nextCoordinates = { 0, 1 };
        }
    }
    else
    {
        std::ostringstream errorMessage;
        errorMessage<< "SpatialAwareness couldn't use the move order: "<< movement<< " to change coordinates ";
        throw std::invalid_argument(errorMessage.str());
    }
    return nextCoordinates;
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
