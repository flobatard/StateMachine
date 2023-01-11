#include<iostream>
#include<StateMachineExample.h>
#include<PrintingStateExample.h>
#include<PrintingPipeExample.h>
#include<ForbidGuard.h>

using namespace std;

int main()
{
    StateMachineExample sm = StateMachineExample();
    
    State* a = new PrintingStateExample(sm, "A");
    State* b = new PrintingStateExample(sm, "B");
    State* c = new PrintingStateExample(sm, "C");
    State* d = new PrintingStateExample(sm, "D");

    Guard* gfAB = new ForbidGuard(sm);
    Guard* gfCB = new ForbidGuard(sm);

    Pipe* pCB = new PrintingPipeExample(sm);
    Pipe* pBC = new PrintingPipeExample(sm);
    Pipe* pCA = new PrintingPipeExample(sm);

    sm.addGuard("A", "B", gfAB);
    sm.addGuard("C", "B", gfCB);

    sm.addPipe("C", "B", pCB);
    sm.addPipe("B", "C", pBC);
    sm.addPipe("C", "A", pCA);
    sm.addPipe("A", "C", pCA);

    sm.addState(a);
    sm.addState(b);
    sm.addState(c);
    sm.addState(d);

    cout << "ENTERING D" << endl;
    sm.transition("D");
    cout << "ENTERING B" << endl;
    sm.transition("B");
    cout << "ENTERING C" << endl;
    sm.transition("C");
    cout << "ENTERING B" << endl;
    sm.transition("B");
    cout << "ENTERING A" << endl;
    sm.transition("A");
    cout << "ENTERING B" << endl;
    sm.transition("B");
    cout << "ENTERING C" << endl;
    sm.transition("C");


    delete(a);
    delete(b);
    delete(c);
    delete(d);
    delete(gfAB);
    delete(gfCB);
    delete(pCB);
    delete(pCA);
    delete(pBC);


    return 0;
}