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

Robot createRobotWithDependencies(const StartupConfigs configs)
{
    std::vector<std::vector<SurfaceSquare>> surface = SurfaceFactory::createSurfaceWithObstacles(configs);
    std::unique_ptr<IPlanet> mars = std::make_unique<Planet>(std::move(surface), configs.planet);
    std::unique_ptr<ISpatialAwareness>spatialAwareness = std::make_unique<SpatialAwareness>(
        std::move(configs.robot.directionFacing),
        std::move(configs.robot.coordinates),
        std::move(configs.robot.coordinateChangeMoveForward),
        std::move(configs.robot.coordinateChangeMoveBackward)
    );
    std::unique_ptr<IMessageInterpreter> messageInterpreter = std::make_unique<MessageInterpreter>(
        std::move(configs.robot.instructionsToMovements),
        std::move(configs.robot.movementsToReadableInstrunctions),
        std::move(configs.robot.directionToReadableDirection));

    Robot robot = Robot(std::move(mars), std::move(spatialAwareness), std::move(messageInterpreter));
    return robot;
}

int main(int argc, char *argv[])
{
    Robot robot;
    try
    {
        const StartupConfigs configs = IO::getStartupConfigs(argc, argv);
        robot = createRobotWithDependencies(configs);
    }
    catch(const std::exception& e)
    {
        std::cerr<< e.what()<< std::endl;
        IO::displayInitialisationUsage();
    }

    while (true)
    {
        try
        {
            const std::string instructions = IO::getUserInput();
            const std::string robotMoveReport = robot.receiveInstructions(instructions);
            IO::returnRobotReport(robotMoveReport);
        }
        catch(const std::exception& e)
        {
            std::cout<< e.what()<< std::endl;
            IO::displayRobotUsage();
        }
    }
}
