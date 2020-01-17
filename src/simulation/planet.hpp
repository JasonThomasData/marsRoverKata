#include <vector>
#include "../configs/planet-config.hpp"
#include "../configs/startup-config.hpp"
#include "coordinates.hpp"
#include "surface-square.hpp"
#include "i_planet.hpp"

#ifndef Planet_h 
#define Planet_h

class Planet: public IPlanet
{
    public:
        Planet();
        Planet(StartupConfigs startupConfig);
        bool isObstacleAtCoordinate(Coordinates coordinates) override;
        int countObstaclesOnSurface() override;
    private:
        int numberOfObstacles;
        std::vector< std::vector<SurfaceSquare> > surface;
        void createSurface(PlanetConfig planetConfig);
        void createObstacles(StartupConfigs startupConfig);
        void checkConfigsValid(PlanetConfig planetConfig);
};

#endif