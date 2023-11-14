#pragma once
#include "./IState.h"
#include <iostream>
using namespace std;

class MetroGate
{
private:
    int cardBalance = 0;

public:
    IState *m_pState = nullptr;
    bool isPaymentComplete = false;
    MetroGate(IState *pState)
    {
        this->m_pState = pState;
    }
    void changeState(IState *pState)
    {
        //IState *pPreviousState = this->m_pState;
        this->m_pState = pState;
        //delete pPreviousState;
    }
    void makePayment(int& balance)
    {
        this->cardBalance = balance;
        this->m_pState->makePayment();
        if(this->isPaymentComplete)
        {
            balance -= 40;
            this->isPaymentComplete = false;
        }
        this->cardBalance = 0;
    }
    void enterGate()
    {
        this->m_pState->enterGate();
    }
    int getCardBalance()
    {
        return cardBalance;
    }
};