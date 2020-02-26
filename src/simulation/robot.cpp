#include <sstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "coordinates.hpp"
#include "directions.hpp"
#include "movements.hpp"
#include "i_planet.hpp"
#include "robot.hpp"
#include "../configs/robot-config.hpp"

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
    std::map<const char, Movement> _instructionsToMovements)
    :planet(std::move(planet)),
    spatialAwareness(std::move(spatialAwareness))//,
    //instructionsToMovements(std::move(instructionsToMovements))
{
    validInstructionsMessage = "f (forward), b (backward), l (left), r (right)";
    instructionsToMovements = std::move(_instructionsToMovements); //Needs to be in constructor for following condition to work
    if(instructionsToMovements.size() == 0)
    {
        std::ostringstream errorMessage;
        errorMessage<< "The robot cannot use a blank map of instructions->Movements";
        throw std::invalid_argument(errorMessage.str());
    }
}

Robot::Robot(){};
