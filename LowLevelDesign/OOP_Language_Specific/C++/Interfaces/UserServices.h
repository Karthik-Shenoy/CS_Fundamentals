#pragma once
#include "InputServices.h"
#include "OutputServices.h"
#include "ServiceFactory.h"

/*
------------------------------------------------------------
User Service Module
------------------------------------------------------------
*/

class User
{
private:
    IUserInput *readerService;
    IUserOutput *writerService;
    ServiceFactory *serviceFactory;

public:
    User(InputServiceType readerType, OutputServiceType writerType, ServiceFactory *serviceFactory /* Dependncy injection*/)
    {
        // serviceFactory = new ServiceFactory(); -----> without dependency injection
        this->serviceFactory = serviceFactory;
        readerService = this->serviceFactory->getReader(readerType);
        writerService = this->serviceFactory->getWriter(writerType);
    }
    void read()
    {
        readerService->read();
    }
    void write()
    {
        writerService->write();
    }
    ~User()
    {
        delete this->serviceFactory;
    }
};