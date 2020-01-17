#ifndef IPlanet_h 
#define IPlanet_h

class IPlanet
{
    public:
        virtual int countObstaclesOnSurface() =0;
        virtual bool isObstacleAtCoordinate(int fromTop, int fromLeft) =0;
};

#endif
