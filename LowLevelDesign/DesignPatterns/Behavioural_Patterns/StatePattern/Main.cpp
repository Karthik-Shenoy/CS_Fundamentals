#include <iostream>
#include "./context.h"
#include "./IState.h"
#include "./ConcreteStates/ClosedState.h"
#include "./ConcreteStates/OpenState.h"
#include "./ConcreteStates/ProcessingState.h"
using namespace std;

// To compile and run your program, you need to link all the source files together
int main()
{
    ClosedState *initialState = new ClosedState();
    MetroGate *metroGate = new MetroGate(initialState);
    initialState->setMetroGate(metroGate);
    int peopleCashList[] = {100, 10};
    // flow makepayment -> enterGate
    // person 1
    metroGate->m_pState->getType();
    metroGate->makePayment(peopleCashList[0]);
    //metroGate->makePayment(peopleCashList[0]);
    metroGate->m_pState->getType();
    metroGate->enterGate();
    metroGate->makePayment(peopleCashList[0]);
    metroGate->enterGate();
    cout << 2 << endl;
    // person 2
    metroGate->makePayment(peopleCashList[1]);
    metroGate->enterGate();
    cout << 3 << endl;
}