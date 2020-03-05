#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <iostream>
#include "../directions.hpp"
#include "../coordinates.hpp"
#include "spatial-awareness.hpp"
#include "movements.hpp"

Coordinates SpatialAwareness::getNextCoordinates(const Movement movement)
{
    Coordinates coordinatesDifference = getCoordinatesDifference(directionFacing, movement);
    return getChangedCoordinates(coordinates, coordinatesDifference);
}

void SpatialAwareness::updateCoordinates(const Coordinates newCoordinates)
{
    coordinates = newCoordinates;
}

Coordinates SpatialAwareness::getChangedCoordinates(Coordinates coordinates, const Coordinates& changeInCoordinates)
{
    coordinates.fromTop += changeInCoordinates.fromTop;
    coordinates.fromLeft += changeInCoordinates.fromLeft;
    return coordinates;
}

Coordinates SpatialAwareness::getCoordinatesDifference(const Direction directionFacing, const Movement movement)
{
    if (movement == Movement::forward)
    {
        return coordinateChangeMoveForward.at(directionFacing);
    }
    else if (movement == Movement::backward)
    {
        return coordinateChangeMoveBackward.at(directionFacing);
    }
    else
    {
        std::ostringstream errorMessage;
        errorMessage<< "SpatialAwareness couldn't use the move order to change coordinates ";
        throw std::invalid_argument(errorMessage.str());
    }
}

Direction SpatialAwareness::getDirectionFacing()
{
    return directionFacing;
}

void SpatialAwareness::turnLeft()
{
    int directionFacingIndex = (int)directionFacing;
    int smallerEnumIndex = directionFacingIndex - 1;
    if (smallerEnumIndex < (int)Direction::min)
    {
        smallerEnumIndex = (int)Direction::max;
    }
    directionFacing = (Direction)smallerEnumIndex;
}

void SpatialAwareness::turnRight() {
    int directionFacingIndex = (int)directionFacing;
    int smallerEnumIndex = directionFacingIndex + 1;
    if (smallerEnumIndex > (int)Direction::max)
    {
        smallerEnumIndex = (int)Direction::min;
    }
    directionFacing = (Direction)smallerEnumIndex;
}

SpatialAwareness::SpatialAwareness(
    Direction directionFacing,
    Coordinates coordinates,
    const std::map<const Direction, Coordinates> coordinateChangeMoveForward,
    const std::map<const Direction, Coordinates> coordinateChangeMoveBackward)
    :coordinateChangeMoveForward(std::move(coordinateChangeMoveForward)),
    coordinateChangeMoveBackward(std::move(coordinateChangeMoveBackward)),
    directionFacing(std::move(directionFacing)),
    coordinates(std::move(coordinates))
{};
