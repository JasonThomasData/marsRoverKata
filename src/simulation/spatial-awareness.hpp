#include <string>

#include "i_spatial-awareness.hpp"
#include "directions.hpp"
#include "movements.hpp"
#include "coordinates.hpp"

#ifndef SpatialAwareness_h 
#define SpatialAwareness_h

class SpatialAwareness : public ISpatialAwareness
{
    public:
        SpatialAwareness();
        SpatialAwareness(Direction directionFacing, Coordinates coordinates);
        Direction getDirectionFacing() override;
        Coordinates getNextCoordinates(Movement movement) override;
        void turnLeft() override;
        void turnRight() override;
    private:
        Coordinates getNextCoordinatesChange(Movement movement);
        Coordinates applyChange(Coordinates coordinates, const Coordinates& changeInCoordinates);
        Direction directionFacing;
        Coordinates coordinates;
};

#endif
