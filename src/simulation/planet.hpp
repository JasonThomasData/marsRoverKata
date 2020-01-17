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
        bool isObstacleAtCoordinate(int fromTop, int fromLeft) override;
        int countObstaclesOnSurface() override;
    private:
        int numberOfObstacles;
        std::vector< std::vector<SurfaceSquare> > surface;
        void createSurface(PlanetConfig planetConfig);
        void createObstacles(PlanetConfig planetConfig);
        void checkConfigsValid(PlanetConfig planetConfig);
};

#endif