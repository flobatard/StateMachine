#include "ForbidGuard.h"

#include <iostream>

ForbidGuard::ForbidGuard(StateMachine& a_stateMachine) : Guard(a_stateMachine)
{

}

bool ForbidGuard::guard()
{
    std::cout << "FORBIDDEN" << std::endl;
    return true;
}