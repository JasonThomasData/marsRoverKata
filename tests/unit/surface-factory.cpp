#include <vector>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/planet/surface-factory.hpp"
#include "../../src/coordinates.hpp"
#include "../../src/directions.hpp"

SCENARIO ("Surface is constructed by factory")
{
    GIVEN ("Valid attributes")
    {
        int surfaceWidth = 2;
        int surfaceHeight = 2;
        int obstacleNumber = 3;
        int robotFromTop = 1;
        int robotFromLeft = 1;
        Direction robotDirection = Direction::west;

        StartupConfigs startupConfigs = {
            { surfaceWidth, surfaceHeight, obstacleNumber },
            { { robotFromTop, robotFromLeft } , robotDirection }
        };

        WHEN("Surface is constructed")
        {
            std::vector<std::vector<SurfaceSquare>> surface = SurfaceFactory::createSurfaceWithObstacles(startupConfigs);

            THEN("Surface has correct number of obstacles and space for robot")
            {
                REQUIRE( surface.at(0).at(0) == SurfaceSquare::obstacle );
                REQUIRE( surface.at(0).at(1) == SurfaceSquare::obstacle );
                REQUIRE( surface.at(1).at(0) == SurfaceSquare::obstacle );
                REQUIRE( surface.at(1).at(1) == SurfaceSquare::null );
            }
        }
    }
}
