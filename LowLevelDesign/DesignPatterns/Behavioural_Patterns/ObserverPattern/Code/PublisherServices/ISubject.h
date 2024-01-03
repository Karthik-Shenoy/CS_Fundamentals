#pragma once
#include "../SubscriberServices/ISubscriber.h"

class ISubject
{
    virtual void subscribe(ISubscriber *subscriber, Event evt) = 0;
    virtual void un_subscribe(ISubscriber *subscriber, Event evt) = 0;
    virtual void notify(Event evt) = 0;
};