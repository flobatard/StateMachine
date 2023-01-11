#include "StateMachine.h"
#include "Guard.h"

class StateMachine;

class ForbidGuard : public Guard 
{
    public:
        ForbidGuard(StateMachine& stateMachine );
        ~ForbidGuard() {};

        bool guard();
};