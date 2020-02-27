#include <sstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "../configs/robot-config.hpp"
#include "../planet/i_planet.hpp"
#include "../coordinates.hpp"
#include "../directions.hpp"
#include "movements.hpp"
#include "robot.hpp"


Robot::Robot(std::unique_ptr<IPlanet> planet,
    std::unique_ptr<ISpatialAwareness> spatialAwareness,
    std::map<const char, Movement> instructionsToMovements)
    :instructionsToMovements(std::move(instructionsToMovements)),
    planet(std::move(planet)),
    spatialAwareness(std::move(spatialAwareness))
{}

Robot::Robot(){};
