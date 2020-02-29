#include <vector>
#include "../configs/robot-config.hpp"
#include "../coordinates.hpp"
#include "../directions.hpp"
#include "../planet/i_planet.hpp"
#include "i_message-interpreter.hpp"
#include "movements.hpp"
#include "i_spatial-awareness.hpp"

#ifndef Robot_h 
#define Robot_h

class Robot
{
    public:
        Robot();
        Robot(std::unique_ptr<IPlanet> planet,
            std::unique_ptr<ISpatialAwareness> spatialAwareness,
            std::unique_ptr<IMessageInterpreter> messageInterpreter);
        std::string receiveInstructions(const std::string& instructions);
    private:
        std::unique_ptr<IMessageInterpreter> messageInterpreter;
        std::unique_ptr<IPlanet> planet;
        std::unique_ptr<ISpatialAwareness> spatialAwareness;
        std::string getMovementInstructionResult(Movement movement);
        std::string getCollisionResult(Coordinates occupiedCoordinates);
        std::string getNewCoordinatesResult(Coordinates newCoordinates);
        std::string getTurnResult(Movement movement);
        //Note - is passing by value or reference cheaper for Enums?
};

#endif