#include "../coordinates.hpp"

#ifndef IPlanet_h 
#define IPlanet_h

class IPlanet
{
    public:
        virtual ~IPlanet() {};
        virtual bool isObstacleAtCoordinate(const Coordinates coordinates) =0;
        virtual Coordinates adjustCoordinatesForSurfaceBoundaries(const Coordinates coordinates) =0;
};

#endif
