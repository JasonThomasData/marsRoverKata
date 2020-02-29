#include <vector>
#include "../configs/planet-config.hpp"
#include "../coordinates.hpp"
#include "surface-square.hpp"
#include "i_planet.hpp"

#ifndef Planet_h 
#define Planet_h

class Planet: public IPlanet
{
    public:
        Planet();
        Planet(std::vector<std::vector<SurfaceSquare>> surface, const PlanetConfig& planetConfig);
        bool isObstacleAtCoordinate(const Coordinates& coordinates) override;
        Coordinates adjustCoordinatesForSurfaceBoundaries(const Coordinates& coordinates) override;
    private:
        int surfaceNorthBoundary;
        int surfaceEastBoundary;
        int surfaceSouthBoundary;
        int surfaceWestBoundary;
        std::vector< std::vector<SurfaceSquare> > surface;
};

#endif