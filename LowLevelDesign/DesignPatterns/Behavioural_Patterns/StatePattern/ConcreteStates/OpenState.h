#pragma once
#include "../IState.h"
#include "../Context.h"
#include "./ClosedState.h"
#include<iostream>
using namespace std;

class OpenState : public IState
{
private:
    MetroGate *m_pMetroGate = nullptr;

public:
    OpenState(MetroGate *pMetroGate)
    {
        this->m_pMetroGate = pMetroGate;
    }
    void makePayment()
    {
        cout << "Open State: Payment Not Allowed Gate already in Open State" << endl;
        return;
    }
    void enterGate() override;
    void processPayment()
    {
        // we can process payment only in processing state
        return;
    }
};

/*

-> the following code causes circular dependency, usually you can fix this my forward declaration 
-> but when creating a new object of the forward declared class, forward declaration results in 'partial type'

void enterGate()
{
    cout << "Entered Gate\n";
    this->metroGate->changeState(new ClosedState(this->metroGate));
    delete this;
    return;
}

*/

