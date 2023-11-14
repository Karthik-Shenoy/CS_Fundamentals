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

// we can process payment only in processing state
void ProcessingState::processPayment()
{
    if(this->m_pMetroGate->getCardBalance() >= 40) 
    {
        // change state (blocks main thread)
        cout << "Processing State : Payment Sucessful" << endl;
        this->updatePaymentState(true);
        this->m_pMetroGate->changeState(new OpenState(this->m_pMetroGate));
    }
    else 
    {
        // change state 
        cout << "Processing State: Payment Failed! insuffecient funds" << endl;
        this->updatePaymentState(false);
        this->m_pMetroGate->changeState(new ClosedState(this->m_pMetroGate));
    }
    
}


/*initial state */
void ClosedState::makePayment()
{
    // all the payment processing is done in the  contructor of the processing state
    cout << "Closed State: Moving to Processing State" << endl;
    this->m_pMetroGate->changeState(new ProcessingState(this->m_pMetroGate));
    this->m_pMetroGate->m_pState->processPayment();
    return;
}
