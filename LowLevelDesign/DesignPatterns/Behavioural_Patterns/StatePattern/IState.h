#pragma once
class IState {
public:
    virtual void makePayment() = 0;
    virtual void enterGate() = 0;
    virtual void processPayment() = 0;
};