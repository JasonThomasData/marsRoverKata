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
#include "report-maker.hpp"

std::string ReportMaker::makeMovementInstructionReport(const Movement movement)
{
    std::ostringstream result;
    result<< "Received instruction to move { "<< getReadableInstruction(movement)<< " }"<< std::endl;
    return result.str();
}

std::string ReportMaker::makeCollisionReport(const Coordinates& occupiedCoordinates)
{
    std::ostringstream result;
    result<< "Hit obstacle at { fromTop: "<< occupiedCoordinates.fromTop<< ", fromLeft: "<< occupiedCoordinates.fromLeft<< " }"<< std::endl;
    result<< "Did not complete move"<< std::endl;
    return result.str();
}

std::string ReportMaker::makeNewCoordinatesReport(const Coordinates& newCoordinates)
{
    std::ostringstream result;
    result<< "Moved to { fromTop: "<< newCoordinates.fromTop<< ", fromLeft: "<< newCoordinates.fromLeft<< " }"<< std::endl;
    return result.str();
}

std::string ReportMaker::makeTurnReport(const Direction directionFacing, const Movement movement)
{
    std::ostringstream result;
    result<< "Turned { "<< getReadableInstruction(movement) << " } and is now facing { "<< getReadableDirection(directionFacing)<< " }"<< std::endl;
    return result.str();
}

std::string ReportMaker::getReadableInstruction(const Movement movement)
{
    return movementsToReadableInstructions.at(movement);
}

std::string ReportMaker::getReadableDirection(const Direction direction)
{
    return directionToReadableDirection.at(direction);
}

ReportMaker::ReportMaker(
    const std::map<const Movement, std::string> movementsToReadableInstructions,
    const std::map<const Direction, std::string> directionToReadableDirection)
    :movementsToReadableInstructions(std::move(movementsToReadableInstructions)),
    directionToReadableDirection(std::move(directionToReadableDirection))
{}
