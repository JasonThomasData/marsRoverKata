#include <string>
#include <map>
#include "i_message-interpreter.hpp"
#include "movements.hpp"

#ifndef MessageInterpreter_h 
#define MessageInterpreter_h

class MessageInterpreter : public IMessageInterpreter
{
    public:
        MessageInterpreter();
        MessageInterpreter(
            std::map<const char, Movement> instructionsToMovements,
            std::map<Movement, const std::string> movementsToReadableInstructions,
            std::map<Direction, const std::string> directionToReadableDirection);
        std::vector<Movement> interpretInstructions(const std::string& instructions) override;
        std::string getReadableInstruction(const Movement& movement) override;
        std::string getReadableDirection(const Direction& direction) override;
    private:
        std::string validInstructionsMessage;
        std::map<const char, Movement> instructionsToMovements;
        std::map<Movement, const std::string> movementsToReadableInstructions;
        std::map<Direction, const std::string> directionToReadableDirection;
        Movement getMovementInstruction(const char instruction);
};

#endif
