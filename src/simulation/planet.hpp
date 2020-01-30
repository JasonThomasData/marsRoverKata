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
        Planet(const StartupConfigs& startupConfig);
        bool isObstacleAtCoordinate(const Coordinates& coordinates) override;
    private:
        std::vector< std::vector<SurfaceSquare> > surface;
        void createSurface(const PlanetConfig& planetConfig);
        void createObstacles(const StartupConfigs& startupConfig);
};

#endif