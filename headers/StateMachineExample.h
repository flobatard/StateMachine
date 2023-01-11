#ifndef STATE_MACHINE_EXAMPLE_HEADER
#define STATE_MACHINE_EXAMPLE_HEADER

#include "StateMachine.h"

class StateMachineExample : public StateMachine
{
    private:
        int nb;

    public:
        void setNb(int other_nb);
        int getNb();

};

#endif