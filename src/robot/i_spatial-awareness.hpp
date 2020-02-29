#include "../coordinates.hpp"
#include "movements.hpp"
#include "../directions.hpp"

#ifndef ISpatialAwareness_h 
#define ISpatialAwareness_h

class ISpatialAwareness
{
    public:
        virtual ~ISpatialAwareness() {};
        virtual Direction getDirectionFacing() =0;
        virtual Coordinates getNextCoordinates(Movement movement) =0;
        virtual void updateCoordinates(Coordinates newCoordinates) =0;
        virtual void turnLeft() =0;
        virtual void turnRight() =0;
};

#endif
