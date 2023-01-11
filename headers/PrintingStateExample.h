#ifndef PRINTING_STATE_EXAMPLE_HEADER
#define PRINTING_STATE_EXAMPLE_HEADER

#include "State.h"
#include "StateMachineExample.h"


class PrintingStateExample : public State
{
    public:
        PrintingStateExample(StateMachineExample& stateMachine, std::string name);
        ~PrintingStateExample() {};
        StateMachineExample& stateMachine;
        bool in();
        bool out();
};

#endif