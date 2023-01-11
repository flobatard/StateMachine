#ifndef MA_CLASSE_HEADER
#define MA_CLASSE_HEADER

#include<map>
#include<string>

class State;
class Pipe;
class Guard;

class StateMachine
{
    public:
        StateMachine();
        ~StateMachine();

        
        
        bool transition(const std::string& state);

        void addState(State* state);
        void addPipe(const std::string& from, const std::string& to, Pipe* pipe);
        void addGuard(const std::string& from, const std::string& to, Guard* guard); 

        std::string getActualState();
        void setActualState(std::string stateName);

        std::string getTransitioningTo();
        void setTransitioningTo(std::string transitioningTo);

        std::string getTransitioningFrom();
        void setTransitioningFrom(std::string transitioningFrom);


    private:
        std::map<std::string, State*> states;
        std::map<std::string, Pipe*> pipes;
        std::map<std::string, Guard*> guards;

        std::string actualState;
        std::string transitioningTo;
        std::string transitioningFrom;


};

#endif //MA_CLASSE_HEADER