#include <vector>
#include "../configs/robot-config.hpp"
#include "i_planet.hpp"

#ifndef Robot_h 
#define Robot_h

class Robot
{
    public:
        Robot();
        Robot(std::unique_ptr<IPlanet> planet, RobotConfig robotConfig);
        std::string receiveInstructions(std::string instructions);
    private:
        std::unique_ptr<IPlanet> planet;
        Coordinates coordinates;
        std::vector<std::string> instructionQueue;
        void establishRobotCoordinates(RobotConfig robotConfig);
};

#endif