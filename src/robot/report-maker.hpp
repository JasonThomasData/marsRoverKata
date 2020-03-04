#include <vector>
#include "../configs/robot-config.hpp"
#include "../coordinates.hpp"
#include "../directions.hpp"
#include "../planet/i_planet.hpp"
#include "i_message-interpreter.hpp"
#include "movements.hpp"
#include "i_spatial-awareness.hpp"
#include "i_report-maker.hpp"

#ifndef ReportMaker_h 
#define ReportMaker_h

class ReportMaker : public IReportMaker
{
    public:
        ReportMaker(
            const std::map<const Movement, std::string> movementsToReadableInstructions,
            const std::map<const Direction, std::string> directionToReadableDirection
        );
        std::string makeMovementInstructionReport(const Movement movement) override;
        std::string makeCollisionReport(const Coordinates& occupiedCoordinates) override;
        std::string makeNewCoordinatesReport(const Coordinates& newCoordinates) override;
        std::string makeTurnReport(const Direction directionFacing, const Movement movement) override;
    private:
        std::string getReadableInstruction(const Movement movement);
        std::string getReadableDirection(const Direction direction);
        const std::map<const Movement, std::string> movementsToReadableInstructions;
        const std::map<const Direction, std::string> directionToReadableDirection;
};

#endif