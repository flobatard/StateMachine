#include"State.h"

#include "StateMachine.h"
State::State(StateMachine& a_stateMachine, std::string a_name) : name(a_name),  stateMachine(a_stateMachine)
{
}