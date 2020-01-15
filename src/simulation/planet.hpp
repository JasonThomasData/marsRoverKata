#ifndef Planet_h 
#define Planet_h

#include <vector>
#include "../configs/planet-config.hpp"
#include "surface.hpp"

class Planet
{
    public:
        Planet(PlanetConfig planetConfig);
        const std::vector< std::vector<Surface> > surface;
    private:
        void CreateSurface(PlanetConfig planetConfig);
        void CreateObstacles(PlanetConfig planetConfig);
};

#endif