#include<iostream>
#include "PrintingPipeExample.h"

PrintingPipeExample::PrintingPipeExample(StateMachineExample& a_stateMachineExample) : Pipe(a_stateMachineExample), stateMachine(a_stateMachineExample)
{

}

bool PrintingPipeExample::pipe()
{
    std::cout << "Actual nb in state : " << stateMachine.getNb() << std::endl;
    std::cout << "Piping from: " << stateMachine.getTransitioningFrom()  <<  "   to: " << stateMachine.getTransitioningTo() << std::endl;
    return false;
}