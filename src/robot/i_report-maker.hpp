#include <string>
#include "movements.hpp"
#include "../coordinates.hpp"
#include "../directions.hpp"

#ifndef IRebotMaker_h 
#define IRebotMaker_h

class IReportMaker
{
    public:
        virtual ~IReportMaker() {};
        virtual std::string makeMovementInstructionReport(const Movement movement) =0;
        virtual std::string makeCollisionReport(const Coordinates& occupiedCoordinates) =0;
        virtual std::string makeNewCoordinatesReport(const Coordinates& newCoordinates) =0;
        virtual std::string makeTurnReport(const Direction directionFacing, const Movement movement) =0;
};

#endif
