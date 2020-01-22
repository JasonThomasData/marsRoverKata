#include <vector>
#include "coordinates.hpp"
#include "i_planet.hpp"
#include "../configs/robot-config.hpp"

#ifndef Robot_h 
#define Robot_h

class Robot
{
    public:
        Robot();
        Robot(std::unique_ptr<IPlanet> planet, RobotConfig robotConfig);
        std::string receiveInstructions(const std::string& instructions);
    private:
        std::unique_ptr<IPlanet> planet;
        Coordinates coordinates;
        std::vector<std::string> instructionQueue;
        void establishRobotCoordinates(Coordinates potentialCoordinates);
};

#endif