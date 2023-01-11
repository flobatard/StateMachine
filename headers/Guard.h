#ifndef GUARD_HEADER
#define GUARD_HEADER

class StateMachine;

class Guard{
    public:
        Guard(StateMachine& stateMachine);
        virtual ~Guard(){};

        StateMachine& stateMachine;
        virtual bool guard() = 0;
};

#endif //GUARD_HEADER