#include <vector>
#include <map>
#include "movements.hpp"

#ifndef IMessageInterpreter_h 
#define IMessageInterpreter_h

class IMessageInterpreter
{
    public:
        virtual ~IMessageInterpreter() {};
        virtual std::vector<Movement> interpretInstructions(const std::string& instructionsToMovements) =0;
        virtual std::string getReadableInstruction(const Movement movement) =0;
        virtual std::string getReadableDirection(const Direction direction) =0;
};

#endif
