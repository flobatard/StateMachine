#include"StateMachine.h"
#include<iostream>

#include<string>

#include "State.h"
#include "Pipe.h"
#include "Guard.h"

using namespace std;

StateMachine::StateMachine()
{
    //cout << "Created" << endl;
}

StateMachine::~StateMachine()
{
    //cout << "Destroyed" <<endl;
}

bool StateMachine::transition(const string& state)
{
    string transName = actualState + "_" + state;

    map<string,State*>::iterator itStateFrom;
    map<string,State*>::iterator itStateTo;

    itStateFrom = states.find(actualState);
    itStateTo = states.find(state);

    
    if (itStateFrom==states.end())
    {
        cerr << "Didn't find actualState : " << actualState << endl;
        return false;
    }

    if (itStateTo==states.end())
    {
        cerr << "Didn't find target state : " << state << endl;
        return false;
    }

    map<string, Guard*>::iterator itGuard;
    itGuard=guards.find(transName);
    bool guarded = false;
    if(itGuard!=guards.end())
    {
        guarded = itGuard->second->guard();
    }
    if (guarded)
    {   
        return false;
    }

    
    itStateFrom->second->out();
    transitioningFrom = actualState;
    transitioningTo = state;
    actualState = "";
    
    map<string, Pipe*>::iterator itPipe;
    itPipe=pipes.find(transName);
    bool piped;
    if (itPipe!=pipes.end())
    {
        piped = itPipe->second->pipe();
    }
    if (!piped)
    {
        actualState=itStateTo->second->name;
        transitioningFrom = "";
        transitioningTo = "";
        itStateTo->second->in();
    }
    return true;
    
};

void StateMachine::addState(State*state)
{
    if (states.empty())
    {
        actualState = state->name;
    }
    states[state->name] = state;
}

void StateMachine::addPipe(const std::string& from, const std::string& to, Pipe* pipe)
{
    pipes[from + "_" + to] = pipe;
}

void StateMachine::addGuard(const std::string& from, const std::string& to, Guard* guard)
{
    guards[from + "_" + to] = guard;
}

string StateMachine::getActualState()
{
    return actualState;
}

string StateMachine::getTransitioningFrom()
{
    return transitioningFrom;
}

string StateMachine::getTransitioningTo()
{
    return transitioningTo;
}

void StateMachine::setActualState(string stateName)
{
    actualState=stateName;
}

void StateMachine::setTransitioningFrom(string stateName)
{
    transitioningFrom=stateName;
}

void StateMachine::setTransitioningTo(string stateName)
{
    transitioningTo=stateName;
}