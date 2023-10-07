#pragma once
#include "./ProcessingState.h"
#include "../IState.h"
#include "../Context.h"
#include<iostream>
using namespace std;

/*initial state */
class ClosedState : public IState
{
private:
    MetroGate *m_pMetroGate = nullptr;

public:
    ClosedState(){}
    ClosedState(MetroGate *pMetroGate)
    {
        this->m_pMetroGate = pMetroGate;
    }
    void makePayment() override;
    void enterGate()
    {
        // we can not enter gate in the closed stae
        cout << "ClosedState : Gate is closed, can not enter" << endl;
        return;
    }
    // setContext
    void setMetroGate(MetroGate *pMetroGate) 
    {
        this->m_pMetroGate = pMetroGate;
    }
    void getType()
    {
        cout << "Closed State" << endl;
    }
};

/*

-> the following code causes circular dependency, usually you can fix this my forward declaration 
-> but when creating a new object of the forward declared class, forward declaration results in 'partial type'

void makePayment()
{
    // all the payment processing is done in the  contructor of the processing state
    this->metroGate->changeState(new ProcessingState(this->metroGate));
    return;
}

*/