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
#include "robot/report-maker.hpp"

Robot createRobot(const StartupConfigs configs)
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
        std::move(configs.robot.instructionsToMovements));
    std::unique_ptr<IReportMaker> reportMaker = std::make_unique<ReportMaker>(
        std::move(configs.robot.movementsToReadableInstrunctions),
        std::move(configs.robot.directionToReadableDirection));

    Robot robot = Robot(
        std::move(mars),
        std::move(spatialAwareness),
        std::move(messageInterpreter),
        std::move(reportMaker));
    return robot;
}

int main(int argc, char *argv[])
{
    try
    {
        //One error should be fatal, the other not fatal. Is this a good way to achieve this?
        const StartupConfigs configs = IO::getStartupConfigs(argc, argv);
        Robot robot = createRobot(configs);

        while (true)
        {
            try
            {
                //consider replacing with if 
                const std::string instructions = IO::getUserInput();
                //Robot should never receive invalid instructions
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
    catch(const std::exception& e)
    {
        std::cerr<< e.what()<< std::endl;
        IO::displayInitialisationUsage();
    }
}
