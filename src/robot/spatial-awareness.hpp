#include <string>
#include <map>
#include "../directions.hpp"
#include "../coordinates.hpp"
#include "i_spatial-awareness.hpp"
#include "movements.hpp"

#ifndef SpatialAwareness_h 
#define SpatialAwareness_h

class SpatialAwareness : public ISpatialAwareness
{
    public:
        SpatialAwareness(
            Direction directionFacing,
            Coordinates coordinates,
            const std::map<const Direction, Coordinates> coordinateChangeMoveForward,
            const std::map<const Direction, Coordinates> coordinateChangeMoveBackward);
        Direction getDirectionFacing() override;
        Coordinates getNextCoordinates(const Movement movement) override;
        void updateCoordinates(const Coordinates newCoordinates) override;
        void turnLeft() override;
        void turnRight() override;
    private:
        const std::map<const Direction, Coordinates> coordinateChangeMoveForward;
        const std::map<const Direction, Coordinates> coordinateChangeMoveBackward;
        Coordinates getCoordinatesDifference(const Direction directionFacing, const Movement movement);
        Coordinates getChangedCoordinates(Coordinates coordinates, const Coordinates& changeInCoordinates);
        Direction directionFacing;
        Coordinates coordinates;
};

#endif
