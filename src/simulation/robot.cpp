#include <sstream>
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
    for(const char& instruction : instructions)
    {
        Movement movement = getMovementInstruction(instruction);
        movements.push_back(movement);
    }
    return movements;
}


Movement Robot::getMovementInstruction(const char& instruction)
{
    //TODO - could this be a map? This might mean information lives in fewer places"
    if (instruction == 'f')
    {
        return Movement::forward;
    }
    else if (instruction == 'b')
    {
        return Movement::backward;
    }
    else if (instruction == 'l')
    {
        return Movement::left;
    }
    else if (instruction == 'r')
    {
        return Movement::right;
    }
    else
    {
        std::ostringstream errorMessage;
        errorMessage<< "The instruction \'"<< instruction<< "\' is not valid. \n Valid instructions are: "<< validInstructionsMessage;
        throw std::invalid_argument(errorMessage.str());
    }
}

Robot::Robot(std::unique_ptr<IPlanet> planet, std::unique_ptr<ISpatialAwareness> spatialAwareness)
    :planet(std::move(planet)),
    spatialAwareness(std::move(spatialAwareness))
{
    validInstructionsMessage = "f (forward), b (backward), l (left), r (right)";
}

Robot::Robot(){};
