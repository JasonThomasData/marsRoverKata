#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <map>
#include "../directions.hpp"
#include "movements.hpp"
#include "message-interpreter.hpp"



std::vector<Movement> MessageInterpreter::interpretInstructions(const std::string& instructions)
{
    if (instructions.empty())
    {
        std::string errorMessage = "A blank instruction is not valid.";
        throw std::invalid_argument(errorMessage);
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
    //this check could happen in shell
    if (instructionsToMovements.count(instruction) == 0) 
    {
        std::ostringstream errorMessage;
        errorMessage<< "The instruction \'"<< instruction<< "\' is not valid";
        throw std::invalid_argument(errorMessage.str());
    }
    else
    {
        return instructionsToMovements.at(instruction);
    }
}

MessageInterpreter::MessageInterpreter(const std::map<const char, Movement> instructionsToMovements)
    :instructionsToMovements(std::move(instructionsToMovements))
{}
