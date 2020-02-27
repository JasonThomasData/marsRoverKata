#include <map>
#include <iostream>
#include <stdexcept>

/////////////////////////////
// CONFIG 

enum Movement
{
    forward,
    backward,
    left,
    right
};

struct Configs
{
    int version = 1;
    std::map<const char, Movement> instructionsToMovements = {
        { 'f' , Movement::forward},
        { 'b' , Movement::backward },
        { 'l' , Movement::left },
        { 'r' , Movement::right }
    };
};

/////////////////////////////
// ROBOT

#ifndef Robot_h 
#define Robot_h
class Robot
{
    public:
        Robot(std::map<const char, Movement> instructionsToMovements)
        :instructionsToMovements(std::move(instructionsToMovements))
        {
            if(this->instructionsToMovements.empty())
            {
                throw std::invalid_argument("Map is blank");
            }
            std::cout<< this->instructionsToMovements['f']<< std::endl;
            std::cout<< this->instructionsToMovements['b']<< std::endl;
            std::cout<< this->instructionsToMovements['l']<< std::endl;
            std::cout<< this->instructionsToMovements['r']<< std::endl;
        }
    private:
        std::map<const char, Movement> instructionsToMovements;
};
#endif

/////////////////////////////
// MAIN 

int main(int argc, char** argv)
{
    Configs configs = Configs();
    Robot(std::move(configs.instructionsToMovements));

    std::map<const char, Movement> localInstructionsToMovements = {
        { 'f' , Movement::forward},
        { 'b' , Movement::backward },
        { 'l' , Movement::left },
        { 'r' , Movement::right }
    };
    Robot(std::move(localInstructionsToMovements));

    return 0;
}
