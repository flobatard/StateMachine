#include<iostream>
#include "PrintingStateExample.h"

PrintingStateExample::PrintingStateExample(StateMachineExample& a_stateMachineExample, std::string a_name) : State(a_stateMachineExample, a_name), stateMachine(a_stateMachineExample)
{

}

bool PrintingStateExample::in()
{
    stateMachine.setNb(stateMachine.getNb() + 1);
    std::cout << "Going in " << name << std::endl;;
    return true;
}

bool PrintingStateExample::out()
{
    std::cout << "Going out " << name << std::endl;
    return true;
}