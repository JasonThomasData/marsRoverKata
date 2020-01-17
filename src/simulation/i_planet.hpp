#include "coordinates.hpp"

#ifndef IPlanet_h 
#define IPlanet_h

class IPlanet
{
    public:
        virtual ~IPlanet() {};
        virtual bool isObstacleAtCoordinate(Coordinates coordinates) =0;
        virtual int countObstaclesOnSurface() =0;
};

#endif
