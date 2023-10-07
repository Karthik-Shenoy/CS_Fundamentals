#pragma once
#include "../IState.h"
#include "../Context.h"
#include "./ClosedState.h"
#include "./OpenState.h"
#include<iostream>
using namespace std;

/**
 * we can't set processing state as the starting state
 * thus there is no default constructor for this state
*/
class ProcessingState : public IState
{
private:
    MetroGate *m_pMetroGate = nullptr;

public:
    ProcessingState(MetroGate *pMetroGate)
    {
        this->m_pMetroGate = pMetroGate;
    }
    void makePayment()
    {
        // this behaviour is not supported in the current state
        cout << "ProcessingState : Can not make Payment Until Previous Payment is Processed" << endl;
        return;
    }
    void enterGate()
    {
        // Gate remains closed in the processing state (issue mentioned in the readme 'Future Work;)
        cout << "ProcessingState : Gate Will Remain Closed Until the Payment is Processed" << endl;
        return;
    }
    void processPayment();
    void getType()
    {
        cout << "Processing State" << endl;
    }
};

/*

-> the following code causes circular dependency, usually you can fix this my forward declaration 
-> but when creating a new object of the forward declared class, forward declaration results in 'partial type'

ProcessingState(MetroGate *metroGate)
{
    if(metroGate->getAmountPaid() >= 40) 
    {
        // change state (blocks main thread)
        this->metroGate->changeState(new OpenState(this->metroGate));
        cout << "Payment Sucessful\n";
        this->metroGate->isPaymentComplete = true;
    }
    else 
    {
        // change state 
        this->metroGate->changeState(new ClosedState(this->metroGate));
        cout << "Payment Failed : insuffecient funds \n";
    }
}

*/