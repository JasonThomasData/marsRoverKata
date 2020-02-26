#include <vector>
#include "coordinates.hpp"
#include "directions.hpp"
#include "movements.hpp"
#include "i_planet.hpp"
#include "i_spatial-awareness.hpp"
#include "../configs/robot-config.hpp"

#ifndef Robot_h 
#define Robot_h

class Robot
{
    public:
        Robot();
        Robot(std::unique_ptr<IPlanet> planet,
            std::unique_ptr<ISpatialAwareness> spatialAwareness,
            std::map<const char, Movement> instructionsToMovements);
        std::vector<Movement> interpretInstructions(const std::string& instructions);
    private:
        std::map<const char, Movement> instructionsToMovements;
        std::string validInstructionsMessage;
        std::unique_ptr<IPlanet> planet;
        std::unique_ptr<ISpatialAwareness> spatialAwareness;
        Movement getMovementInstruction(const char instruction);
        std::vector<std::string> instructionQueue;
        void validateRobotCoordinates(const Coordinates& potentialCoordinates);
        bool checkInstructionIsValid(const char& instruction);
};

#endif