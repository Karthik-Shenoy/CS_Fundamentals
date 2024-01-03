#pragma once
#include <string>

// enum that represents different events that can be performed
enum Event
{
    EVENT_READ = 0,
    EVENT_WRITE = 1
};


// struct for storing operations
struct Operation
{
    Event evt;
    std::string account_id;
    int withdrawal_amount = 0;
};


