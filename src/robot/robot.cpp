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

std::string Robot::receiveInstructions(const std::string& instructions)
{
    std::vector<Movement> movementsToPerform = messageInterpreter->interpretInstructions(instructions);
    std::string results;
    for(Movement movement : movementsToPerform)
    {
        results.append(reportMaker->makeMovementInstructionReport(movement));
        if(movement == Movement::forward || movement == Movement::backward)
        {
            Coordinates potentialNextCoordinates = spatialAwareness->getNextCoordinates(movement);
            Coordinates adjustedNextCoordinates = planet->adjustCoordinatesForSurfaceBoundaries(potentialNextCoordinates);
            bool coordinatesOccupied = planet->isObstacleAtCoordinate(adjustedNextCoordinates);
            if(coordinatesOccupied)
            {
                std::string report = reportMaker->makeCollisionReport(adjustedNextCoordinates);
                results.append(report);
            }
            else
            {
                spatialAwareness->updateCoordinates(adjustedNextCoordinates);
                std::string report = reportMaker->makeNewCoordinatesReport(adjustedNextCoordinates);
                results.append(report);
            }
        }
        else if (movement == Movement::left)
        {
            spatialAwareness->turnLeft();
            Direction directionFacing = spatialAwareness->getDirectionFacing();
            std::string report = reportMaker->makeTurnReport(directionFacing, movement);
            results.append(report);
        }
        else if (movement == Movement::right)
        {
            Direction directionFacing = spatialAwareness->getDirectionFacing();
            spatialAwareness->turnRight();
            std::string report = reportMaker->makeTurnReport(directionFacing, movement);
            results.append(report);
        }
    }
    return results;
}

Robot::Robot(std::unique_ptr<IPlanet> planet,
    std::unique_ptr<ISpatialAwareness> spatialAwareness,
    std::unique_ptr<IMessageInterpreter> messageInterpreter,
    std::unique_ptr<IReportMaker> reportMaker)
    :messageInterpreter(std::move(messageInterpreter)),
    planet(std::move(planet)),
    spatialAwareness(std::move(spatialAwareness)),
    reportMaker(std::move(reportMaker))
{}
