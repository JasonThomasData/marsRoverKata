#include <iostream>
#include <vector>
#include "configs/startup-config.hpp"
#include "io.hpp"
#include "planet/planet.hpp"
#include "planet/surface-factory.hpp"
#include "planet/surface-square.hpp"
#include "robot/robot.hpp"
#include "robot/spatial-awareness.hpp"
#include "robot/message-interpreter.hpp"

int main(int argc, char *argv[])
{
    StartupConfigs configs;
    std::unique_ptr<IPlanet> mars;
    std::unique_ptr<ISpatialAwareness> spatialAwareness;
    std::unique_ptr<IMessageInterpreter> messageInterpreter;
    Robot robot;
    try
    {
        configs = IO::getStartupConfigs(argc, argv);

        std::vector<std::vector<SurfaceSquare>> surface = SurfaceFactory::createSurfaceWithObstacles(configs);
        mars = std::make_unique<Planet>(std::move(surface), configs.planet);
        spatialAwareness = std::make_unique<SpatialAwareness>(
            std::move(configs.robot.directionFacing),
            std::move(configs.robot.coordinates),
            std::move(configs.robot.coordinateChangeMoveForward),
            std::move(configs.robot.coordinateChangeMoveBackward)
        );
        messageInterpreter = std::make_unique<MessageInterpreter>(
            std::move(configs.robot.instructionsToMovements),
            std::move(configs.robot.movementsToReadableInstrunctions),
            std::move(configs.robot.directionToReadableDirection));
        robot = Robot(std::move(mars), std::move(spatialAwareness), std::move(messageInterpreter));
    }
    catch(const std::exception& e)
    {
        std::cerr<< e.what()<< std::endl;
        IO::displayInitialisationUsage();
    }

    try
    {

        std::string robotMoveReport = robot.receiveInstructions(std::move("flfrbrfl"));
        std::cout<< robotMoveReport<< std::endl;
        /*
        while (true)
        {
            std::string instructions = IO::getInstructions();
            std::string robotMoveReport = robot.interpretInstructions(std::move(instructions));
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
