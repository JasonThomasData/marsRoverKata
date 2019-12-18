#include <iostream>

int main(int argc, char **argv)
{
    struct configs = IO::getMarsConfigs(argv);
    Planet mars = new Planet(marsConfigs);
    MarsRover rover = new Rover(&mars);

    while (true)
    {
        std::string instructions = IO::getInstructions();
        std::string roverMoveReport = rover.interpretAndApplyInstructions(instructions);
        IO::returnOutput(roverMoveReport);
    }

    return 0;
}

