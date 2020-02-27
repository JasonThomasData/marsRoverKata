#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <iostream>
#include "../directions.hpp"
#include "../coordinates.hpp"
#include "spatial-awareness.hpp"
#include "movements.hpp"

Coordinates SpatialAwareness::getNextCoordinates(Movement movement)
{
    Coordinates changeInCoordinates = getNextCoordinatesChange(movement);
    std::cout<< "Top: "<< changeInCoordinates.fromTop<< " Left: "<< changeInCoordinates.fromLeft<< std::endl;
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
    std::cout<< "Movement: "<< movement << std::endl;
    if (movement == Movement::forward)
    {
        return coordinateChangeMoveForward[directionFacing];
    }
    else if (movement == Movement::backward)
    {
        return coordinateChangeMoveBackward[directionFacing];
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
    std::map<Direction, Coordinates> coordinateChangeMoveForward,
    std::map<Direction, Coordinates> coordinateChangeMoveBackward)
    :directionFacing(std::move(directionFacing)),
    coordinates(std::move(coordinates)),
    coordinateChangeMoveForward(std::move(coordinateChangeMoveForward)),
    coordinateChangeMoveBackward(std::move(coordinateChangeMoveBackward))
{};
