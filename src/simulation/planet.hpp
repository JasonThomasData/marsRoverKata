#include <vector>
#include "../configs/planet-config.hpp"
#include "surface-square.hpp"
#include "i_planet.hpp"

#ifndef Planet_h 
#define Planet_h

class Planet: public IPlanet
{
    public:
        Planet();
        Planet(PlanetConfig planetConfig);
        SurfaceSquare whatIsAtCoordinate(int fromTop, int fromLeft) override;
    private:
        std::vector< std::vector<SurfaceSquare> > surface;
        void createSurface(PlanetConfig planetConfig);
        void createObstacles(PlanetConfig planetConfig);
        void checkConfigsValid(PlanetConfig planetConfig);
};

#endif