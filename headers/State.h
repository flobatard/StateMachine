#ifndef STATE_HEADER
#define STATE_HEADER

#include <string>

class StateMachine;

class State{
    public:
        State(StateMachine& stateMachine, std::string name);
        virtual ~State() {};

        std::string name;
        StateMachine& stateMachine;

        virtual bool in() = 0;
        virtual bool out() = 0;
};


#endif //STATE_HEADER