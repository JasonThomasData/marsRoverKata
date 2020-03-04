#include <vector>
#include "../configs/robot-config.hpp"
#include "../coordinates.hpp"
#include "../directions.hpp"
#include "../planet/i_planet.hpp"
#include "i_message-interpreter.hpp"
#include "movements.hpp"
#include "i_spatial-awareness.hpp"
#include "i_report-maker.hpp"

#ifndef Robot_h 
#define Robot_h

class Robot
{
    public:
        Robot(std::unique_ptr<IPlanet> planet,
            std::unique_ptr<ISpatialAwareness> spatialAwareness,
            std::unique_ptr<IMessageInterpreter> messageInterpreter,
            std::unique_ptr<IReportMaker> reportMaker);
        std::string receiveInstructions(const std::string& instructions);
    private:
        std::unique_ptr<IMessageInterpreter> messageInterpreter;
        std::unique_ptr<IPlanet> planet;
        std::unique_ptr<ISpatialAwareness> spatialAwareness;
        std::unique_ptr<IReportMaker> reportMaker;
};

#endif