#include "../IState.h"
#include "../Context.h"
#include "./ClosedState.h"
#include "./OpenState.h"
#include "./ProcessingState.h"
#include<iostream>
using namespace std;

// implement/define all the methods that have circular dependency here
// ReturnType ClassName::method() {implementation}

void OpenState::enterGate()
{
    cout << "Open State: Entered Gate" << endl;
    this->m_pMetroGate->changeState(new ClosedState(this->m_pMetroGate));
    // delete this;
    return;
}


void ProcessingState::processPayment()
{
    
    if(this->m_pMetroGate->getCardBalance() >= 40) 
    {
        // change state (blocks main thread)
        cout << "Processing State : Payment Sucessful" << endl;
        this->m_pMetroGate->isPaymentComplete = true;
        this->m_pMetroGate->changeState(new OpenState(this->m_pMetroGate));
        cout << "ProcessPaymentFunc : " ;
        this->m_pMetroGate->m_pState->getType();
    }
    else 
    {
        // change state 
        this->m_pMetroGate->changeState(new ClosedState(this->m_pMetroGate));
        cout << "Processing State: Payment Failed! insuffecient funds" << endl;

    }
    
}


/*initial state */
void ClosedState::makePayment()
{
    // all the payment processing is done in the  contructor of the processing state
    cout << "Closed State: Moving to Processing State" << endl;
    this->m_pMetroGate->changeState(new ProcessingState(this->m_pMetroGate));
    return;
}
