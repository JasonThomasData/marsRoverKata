#include <vector>
#include "coordinates.hpp"
#include "directions.hpp"
#include "i_planet.hpp"
#include "../configs/robot-config.hpp"

#ifndef Robot_h 
#define Robot_h

class Robot
{
    public:
        Robot();
        Robot(std::unique_ptr<IPlanet> planet, RobotConfig robotConfig);
        std::string interpretAndApplyInstructions(const std::string& instructions);
    private:
        std::unique_ptr<IPlanet> planet;
        Coordinates coordinates;
        Direction direction;
        std::vector<std::string> instructionQueue;
        void validateRobotCoordinates(const Coordinates& potentialCoordinates);
        bool checkInstructionIsValid(const char& instruction);
};

#endif