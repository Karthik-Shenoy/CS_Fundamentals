#pragma once
#include "../PublisherServices/PublisherTypes.h"
#include "./ISubscriber.h"
#include <iostream>

class EmailNotificationService : public ISubscriber
{
public:
    void update(Operation operation)
    {
        cout << "\n-----------------------------------\n" << "Email Service" << "\n-----------------------------------\n";
        string event_desc = (operation.evt == EVENT_READ ? "Read account info" : "Withdrew " + to_string(operation.withdrawal_amount));
        cout << "Sending email \n { to: " << operation.account_id <<  ", event:" <<  event_desc << " }\n";
    }
};