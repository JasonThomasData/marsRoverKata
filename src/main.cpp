#include <iostream>

int main(int argc, char **argv)
{
    for (int i=0; i<argc; i++)
    {
        std::cout << "Parameter " << i << " was " << argv[i] << std::endl;
    }

    //StartupConfigs configs = IO::geStartupConfigs(argv);
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

