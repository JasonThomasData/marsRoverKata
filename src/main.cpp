#include <iostream>
#include "configs/startup-config.hpp"
#include "io.hpp"
#include "simulation/planet/planet.hpp"
#include "simulation/robot/robot.hpp"
#include "simulation/robot/spatial-awareness.hpp"

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
        spatialAwareness = std::make_unique<SpatialAwareness>(
            std::move(configs.robot.directionFacing),
            std::move(configs.robot.coordinates),
            std::move(configs.robot.coordinateChangeMoveForward),
            std::move(configs.robot.coordinateChangeMoveBackward)
        );
        robot = Robot(std::move(mars), std::move(spatialAwareness), std::move(configs.robot.instructionsToMovements));
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
