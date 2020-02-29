#include <sstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "../configs/robot-config.hpp"
#include "../planet/i_planet.hpp"
#include "i_message-interpreter.hpp"
#include "message-interpreter.hpp"
#include "../coordinates.hpp"
#include "../directions.hpp"
#include "movements.hpp"
#include "robot.hpp"

std::string Robot::getMovementInstructionResult(Movement movement)
{
    std::ostringstream result;
    result<< "Received instruction to move { "<< messageInterpreter->getReadableInstruction(movement)<< " }"<< std::endl;
    return result.str();
}

std::string Robot::getCollisionResult(Coordinates occupiedCoordinates)
{
    std::ostringstream result;
    result<< "Hit obstacle at { fromTop: "<< occupiedCoordinates.fromTop<< ", fromLeft: "<< occupiedCoordinates.fromLeft<< " }"<< std::endl;
    result<< "Did not complete move"<< std::endl;
    return result.str();
}

std::string Robot::getNewCoordinatesResult(Coordinates newCoordinates)
{
    std::ostringstream result;
    result<< "Moved to { fromTop: "<< newCoordinates.fromTop<< ", fromLeft: "<< newCoordinates.fromLeft<< " }"<< std::endl;
    return result.str();
}

std::string Robot::getTurnResult(Movement movement)
{
    std::ostringstream result;
    Direction directionFacing = spatialAwareness->getDirectionFacing();
    result<< "Turned { "<< messageInterpreter->getReadableInstruction(movement) << " } and is now facing { "<<  messageInterpreter->getReadableDirection(directionFacing)<< " }"<< std::endl;
    return result.str();
}

std::string Robot::receiveInstructions(const std::string& instructions)
{
    std::vector<Movement> movementsToPerform = messageInterpreter->interpretInstructions(instructions);
    std::string results;
    for(Movement movement : movementsToPerform)
    {
        results.append(getMovementInstructionResult(movement));
        if(movement == Movement::forward || movement == Movement::backward)
        {
            Coordinates potentialNextCoordinates = spatialAwareness->getNextCoordinates(movement);
            Coordinates adjustedNextCoordinates = planet->adjustCoordinatesForSurfaceBoundaries(potentialNextCoordinates);
            bool coordinatesOccupied = planet->isObstacleAtCoordinate(adjustedNextCoordinates);
            if(coordinatesOccupied)
            {
                results.append(getCollisionResult(adjustedNextCoordinates));
                return results;
            }
            else
            {
                spatialAwareness->updateCoordinates(adjustedNextCoordinates);
                results.append(getNewCoordinatesResult(adjustedNextCoordinates));
            }
        }
        else if (movement == Movement::left)
        {
            spatialAwareness->turnLeft();
            results.append(getTurnResult(movement));
        }
        else if (movement == Movement::right)
        {
            spatialAwareness->turnRight();
            results.append(getTurnResult(movement));
        }
    }
    return results;
}

Robot::Robot(std::unique_ptr<IPlanet> planet,
    std::unique_ptr<ISpatialAwareness> spatialAwareness,
    std::unique_ptr<IMessageInterpreter> messageInterpreter)
    :messageInterpreter(std::move(messageInterpreter)),
    planet(std::move(planet)),
    spatialAwareness(std::move(spatialAwareness))
{}

Robot::Robot(){};
