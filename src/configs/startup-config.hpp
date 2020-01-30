#include "planet-config.hpp"
#include "robot-config.hpp"

#ifndef StartupConfigs_hpp
#define StartupConfigs_hpp

class StartupConfigs
{
    public:
        StartupConfigs(const PlanetConfig planet, const RobotConfig robot);
        StartupConfigs();
        PlanetConfig planet;
        RobotConfig robot;
    private:
        void checkObstaclesFewerThanSurfaceArea();
        void checkSpaceForRobot();
        void checkRobotIsOnSurface();
};
#endif
