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
        MessageInterpreter(std::map<const char, Movement> instructionsToMovements);
        std::vector<Movement> interpretInstructions(const std::string& instructions) override;
    private:
        std::string validInstructionsMessage;
        std::map<const char, Movement> instructionsToMovements;
        Movement getMovementInstruction(const char instruction);
};

#endif
