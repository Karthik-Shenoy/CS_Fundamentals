#pragma once
#include <map>
#include <iostream>
#include "./PublisherTypes.h"
#include "./ISubject.h"
#include "../SubscriberServices/ISubscriber.h"
#include <vector>
#include <mutex>
#include "DatabaseController.h"
using namespace std;

class AccountTransactionManager : public ISubject
{
private:
    map<Event, vector<ISubscriber *>> event_subscribers_map;
    mutex notification_mutex;
    Operation last_operation;
    DatabaseController *db_controller;

    void update_operation_and_notify(Event evt, string account_id, int withdrawal_amount = 0)
    {
        // acquire lock and release after notification
        lock_guard<mutex> lockGuard(notification_mutex);
        last_operation.evt = evt;
        last_operation.account_id = account_id;
        last_operation.withdrawal_amount = withdrawal_amount;

        this->notify(evt);
    }
    void notify(Event evt)
    {
        if (event_subscribers_map.find(evt) == event_subscribers_map.end())
            return;
        for (ISubscriber *subscriber : this->event_subscribers_map[evt])
        {
            subscriber->update(last_operation);
        }
    }

public:
    AccountTransactionManager(DatabaseController *db_controller)
    {
        this->db_controller = db_controller;
    }

    void subscribe(ISubscriber *subscriber, Event evt)
    {
        event_subscribers_map[evt].push_back(subscriber);
    }

    void un_subscribe(ISubscriber *subscriber, Event evt)
    {
        if (event_subscribers_map.find(evt) == event_subscribers_map.end())
            return;
        event_subscribers_map[evt].pop_back();
    };

    void get_account_balance(string account_id)
    {
        this->db_controller->read(account_id);
        update_operation_and_notify(Event::EVENT_READ, account_id);
    }

    void withdraw_money(string account_id, int withdrawal_amount)
    {
        this->db_controller->update(account_id, withdrawal_amount);
        update_operation_and_notify(Event::EVENT_WRITE, account_id, withdrawal_amount);
    }
};