#include <iostream>
#include "configs/StartupConfigs.hpp"
#include "IO.hpp"

int main(int argc, char *argv[])
{
    StartupConfigs configs = IO::getStartupConfigs(argv);
    std::cout<< configs.planet.surfaceWidth<< std::endl;
    std::cout<< configs.planet.surfaceHeight<< std::endl;
    std::cout<< configs.planet.obstacleNumber<< std::endl;
    std::cout<< configs.robot.x_coordinate << std::endl;
    std::cout<< configs.robot.y_coordinate << std::endl;

    /*
    Planet mars = new Planet(configs.planet);
    MarsRover rover = new Rover(&mars, configs.rover);

    while (true)
    {
        std::string instructions = IO::getInstructions();
        std::string roverMoveReport = rover.interpretAndApplyInstructions(instructions);
        IO::returnOutput(roverMoveReport);
    }

    return 0;
    */
}

