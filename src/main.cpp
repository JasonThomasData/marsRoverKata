#include <iostream>
#include "configs/startup-config.hpp"
#include "io.hpp"
#include "simulation/planet.hpp"
#include "simulation/robot.hpp"
#include "simulation/spatial-awareness.hpp"

int main(int argc, char *argv[])
{
    StartupConfigs configs;
    std::unique_ptr<IPlanet> mars;
    std::unique_ptr<ISpatialAwareness> spatialAwareness;
    Robot robot;
    try
    {
        configs = IO::getStartupConfigs(argc, argv);
        mars = std::make_unique<Planet>(configs);
        spatialAwareness = std::make_unique<SpatialAwareness>(std::move(configs.robot.directionFacing), std::move(configs.robot.coordinates));
        robot = Robot(std::move(mars), std::move(spatialAwareness));
    }
    catch(const std::exception& e)
    {
        std::cerr<< e.what()<< std::endl;
        IO::displayInitialisationUsage();
    }

    try
    {
        /*
        while (true)
        {
            std::string instructions = IO::getInstructions();
            std::string roverMoveReport = rover.interpretAndApplyInstructions(std::move(instructions));
            IO::returnOutput(roverMoveReport);
        }

        return 0;
        */
    }
    catch(const std::exception& e)
    {
        std::cerr<< e.what()<< std::endl;
    }
}
