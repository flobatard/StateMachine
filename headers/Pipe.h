#ifndef PIPE_HEADER
#define PIPE_HEADER

class StateMachine;

class Pipe{
    public:
        Pipe(StateMachine& stateMachine);
        virtual ~Pipe() {};

        StateMachine& stateMachine;
        virtual bool pipe() = 0;
};

#endif // PIPE_HEADER