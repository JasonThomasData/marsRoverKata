#include <vector>
#include <stdexcept>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/directions.hpp"
#include "../../src/robot/robot.hpp"
#include "../../src/robot/spatial-awareness.hpp"
#include "../../src/planet/i_planet.hpp"
#include "../../src/planet/planet.hpp"
#include "../../src/coordinates.hpp"

/*
class TestFixtures 
{
    private:
        int surfaceWidth = 14;
        int surfaceHeight = 3;
        int obstacleNumber = 5;
        int robotFromTop = 1;
        int robotFromLeft = 1;
        Direction robotDirection = Direction::south;
        Coordinates coordinates = { robotFromTop, robotFromLeft };
        const StartupConfigs startupConfigs = {
            { surfaceWidth, surfaceHeight, obstacleNumber },
            { coordinates, robotDirection }
        };
    public:
        std::unique_ptr<IPlanet> planet = std::make_unique<Planet>(startupConfigs);
        std::unique_ptr<ISpatialAwareness> spatialAwareness = std::make_unique<SpatialAwareness>(
            robotDirection,
            coordinates,
            startupConfigs.robot.coordinateChangeMoveForward,
            startupConfigs.robot.coordinateChangeMoveBackward);
        std::map<const char, Movement> instructionsToMovements = {
            { 'f', Movement::forward },
            { 'b', Movement::backward },
            { 'l', Movement::left },
            { 'r', Movement::right }
        };
};
*/
