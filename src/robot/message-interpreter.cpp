#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <map>
#include "movements.hpp"
#include "message-interpreter.hpp"

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
        return instructionsToMovements[instruction];
    }
}

MessageInterpreter::MessageInterpreter(std::map<const char, Movement> instructionsToMovements)
:instructionsToMovements(std::move(instructionsToMovements))
{
    validInstructionsMessage = "f (forward), b (backward), l (left), r (right)";
    if(this->instructionsToMovements.empty())
    {
        std::ostringstream errorMessage;
        errorMessage<< "The robot cannot use a blank map of instructions->Movements";
        throw std::invalid_argument(errorMessage.str());
    }
}

MessageInterpreter::MessageInterpreter(){}
