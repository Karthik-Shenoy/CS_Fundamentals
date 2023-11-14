#pragma once
class IIterator {
public:
    virtual IIterator* moveNext() = 0;
    virtual bool hasMore() = 0;
    virtual void display() = 0;
};