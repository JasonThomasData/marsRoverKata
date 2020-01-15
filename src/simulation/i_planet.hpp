#include "surface-square.hpp"

#ifndef IPlanet_h 
#define IPlanet_h

class IPlanet
{
    public:
        virtual SurfaceSquare whatIsAtCoordinate(int fromTop, int fromLeft) =0;
};

#endif
