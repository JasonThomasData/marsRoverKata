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
            const std::map<const char, Movement> instructionsToMovements,
            const std::map<const Movement, std::string> movementsToReadableInstructions,
            const std::map<const Direction, std::string> directionToReadableDirection);
        std::vector<Movement> interpretInstructions(const std::string& instructions) override;
        std::string getReadableInstruction(const Movement& movement) override;
        std::string getReadableDirection(const Direction& direction) override;
    private:
        std::string validInstructionsMessage;
        const std::map<const char, Movement> instructionsToMovements;
        const std::map<const Movement, std::string> movementsToReadableInstructions;
        const std::map<const Direction, std::string> directionToReadableDirection;
        Movement getMovementInstruction(const char instruction);
};

#endif
