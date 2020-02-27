#include <map>
#include "movements.hpp"

#ifndef Robot_h 
#define Robot_h
class Robot
{
    public:
        Robot::Robot(std::map<const char, Movement> instructionsToMovements);
    private:
        std::map<const char, Movement> instructionsToMovements;
};
#endif