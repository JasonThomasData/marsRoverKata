#include <sstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "../coordinates.hpp"
#include "../directions.hpp"
#include "../planet/i_planet.hpp"
#include "../../configs/robot-config.hpp"
#include "movements.hpp"
#include "robot.hpp"

std::vector<Movement> Robot::interpretInstructions(const std::string& instructions)
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


Movement Robot::getMovementInstruction(const char instruction)
{
    //if (instructionsToMovements.find(instruction) == instructionsToMovements.end()) 
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

Robot::Robot(std::unique_ptr<IPlanet> planet,
    std::unique_ptr<ISpatialAwareness> spatialAwareness,
    std::map<const char, Movement> instructionsToMovements)
    :instructionsToMovements(std::move(instructionsToMovements)),
    planet(std::move(planet)),
    spatialAwareness(std::move(spatialAwareness))
{
    validInstructionsMessage = "f (forward), b (backward), l (left), r (right)";
    if(this->instructionsToMovements.empty())
    {
        std::ostringstream errorMessage;
        errorMessage<< "The robot cannot use a blank map of instructions->Movements";
        throw std::invalid_argument(errorMessage.str());
    }
}

Robot::Robot(){};
