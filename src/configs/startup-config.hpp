#include "planet-config.hpp"
#include "robot-config.hpp"

#ifndef StartupConfigs_hpp
#define StartupConfigs_hpp

class StartupConfigs
{
    public:
        StartupConfigs(PlanetConfig planet, RobotConfig robot);
        StartupConfigs();
        PlanetConfig planet;
        RobotConfig robot;
    private:
        void checkObstaclesFewerThanSurfaceArea();
        void checkSpaceForRobot();
        void checkRobotIsOnSurface();
        //Check valid stuff
};
#endif
