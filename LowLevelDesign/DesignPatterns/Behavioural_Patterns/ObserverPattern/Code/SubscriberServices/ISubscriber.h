#pragma once
#include <string>
#include "../PublisherServices/PublisherTypes.h"
using namespace std;
class ISubscriber
{
public:
    virtual void update(Operation oper) = 0;
};