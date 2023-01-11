#ifndef PRINTING_PIPE_EXAMPLE_HEADER
#define PRINTING_PIPE_EXAMPLE_HEADER

#include "Pipe.h"
#include "StateMachineExample.h"

class PrintingPipeExample : public Pipe
{
    public:
        PrintingPipeExample(StateMachineExample& stateMachine);
        ~PrintingPipeExample() {};
        StateMachineExample& stateMachine;

        bool pipe();
};

#endif