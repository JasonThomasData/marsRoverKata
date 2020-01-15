#include <iostream>
#include "configs/StartupConfigs.hpp"
#include "IO.hpp"
#include "simulation/planet.hpp"


int main(int argc, char *argv[])
{
    try
    {
        StartupConfigs configs;
        configs = IO::getStartupConfigs(argc, argv);
        Planet mars = Planet(configs.planet);
        //MarsRover rover = new Rover(&mars, configs.rover);
    }
    catch(const std::exception& e)
    {
        std::cerr<< e.what()<< std::endl;
    }

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

