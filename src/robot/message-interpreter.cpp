#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <map>
#include "../directions.hpp"
#include "movements.hpp"
#include "message-interpreter.hpp"

std::string MessageInterpreter::getReadableInstruction(const Movement movement)
{
    return movementsToReadableInstructions.at(movement);
}

std::string MessageInterpreter::getReadableDirection(const Direction direction)
{
    return directionToReadableDirection.at(direction);
}

std::vector<Movement> MessageInterpreter::interpretInstructions(const std::string& instructions)
{
    if (instructions.empty())
    {
        std::ostringstream errorMessage;
        errorMessage<< "A blank instruction is not valid. \n Valid instructions are: "<< validInstructionsMessage;
        throw std::invalid_argument(errorMessage.str());
    }
    std::vector<Movement> movements;
    for(const char instruction : instructions)
    {
        Movement movement = getMovementInstruction(instruction);
        movements.push_back(movement);
    }
    return movements;
}

Movement MessageInterpreter::getMovementInstruction(const char instruction)
{
    if (instructionsToMovements.count(instruction) == 0) 
    {
        std::ostringstream errorMessage;
        errorMessage<< "The instruction \'"<< instruction<< "\' is not valid. \n Valid instructions are: "<< validInstructionsMessage;
        throw std::invalid_argument(errorMessage.str());
    }
    else
    {
        return instructionsToMovements.at(instruction);
    }
}

MessageInterpreter::MessageInterpreter(const std::map<const char, Movement> instructionsToMovements,
    const std::map<const Movement, std::string> movementsToReadableInstructions,
    const std::map<const Direction, std::string> directionToReadableDirection)
    :instructionsToMovements(std::move(instructionsToMovements)),
    movementsToReadableInstructions(std::move(movementsToReadableInstructions)),
    directionToReadableDirection(std::move(directionToReadableDirection))
{
    if(this->instructionsToMovements.empty())
    {
        std::ostringstream errorMessage;
        errorMessage<< "The robot cannot use a blank map of instructions->Movements";
        throw std::invalid_argument(errorMessage.str());
    }
    if(this->movementsToReadableInstructions.empty())
    {
        std::ostringstream errorMessage;
        errorMessage<< "The robot cannot use a blank map of movements->ReadableInstructions";
        throw std::invalid_argument(errorMessage.str());
    }
    if(this->directionToReadableDirection.empty())
    {
        std::ostringstream errorMessage;
        errorMessage<< "The robot cannot use a blank map of directions->ReadableDirections";
        throw std::invalid_argument(errorMessage.str());
    }
    validInstructionsMessage = "f (forward), b (backward), l (left), r (right)";
}

MessageInterpreter::MessageInterpreter(){}
