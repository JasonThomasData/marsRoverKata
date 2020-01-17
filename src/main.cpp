#include <iostream>
#include "configs/startup-config.hpp"
#include "io.hpp"
#include "simulation/planet.hpp"


int main(int argc, char *argv[])
{
    StartupConfigs configs;
    Planet mars;
    //MarsRover rover;
    try
    {
        configs = IO::getStartupConfigs(argc, argv);
        mars = Planet(configs);
        //rover = Robot(&mars, configs.robot);
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
            std::string roverMoveReport = rover.interpretAndApplyInstructions(instructions);
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
