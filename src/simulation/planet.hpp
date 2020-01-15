#ifndef Planet_h 
#define Planet_h

#include <vector>
#include "../configs/PlanetConfig.hpp"
#include "surface.hpp"

class Planet
{
    public:
        Planet(PlanetConfig planetConfig);
    private:
        std::vector<std::vector<Surface> > surface;
        void CreateSurface(PlanetConfig planetConfig);
        void CreateObstacles(PlanetConfig planetConfig);
};

#endif