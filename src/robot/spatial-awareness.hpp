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
        SpatialAwareness();
        SpatialAwareness(
            Direction directionFacing,
            Coordinates coordinates,
            std::map<Direction, Coordinates> coordinateChangeMoveForward,
            std::map<Direction, Coordinates> coordinateChangeMoveBackward);
        Direction getDirectionFacing() override;
        Coordinates getNextCoordinates(Movement movement) override;
        void updateCoordinates(Coordinates newCoordinates) override;
        void turnLeft() override;
        void turnRight() override;
    private:
        std::map<Direction, Coordinates> coordinateChangeMoveForward;
        std::map<Direction, Coordinates> coordinateChangeMoveBackward;
        Coordinates getCoordinatesDifference(Movement movement);
        Coordinates getChangedCoordinates(Coordinates coordinates, const Coordinates& changeInCoordinates);
        Direction directionFacing;
        Coordinates coordinates;
};

#endif
