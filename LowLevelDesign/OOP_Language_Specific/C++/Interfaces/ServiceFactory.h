#pragma once
#include "InputServices.h"
#include "OutputServices.h"
#include "Types.h"
#include "vector"

/*
------------------------------------------------------------
Service Factory Module
------------------------------------------------------------
*/

class ServiceFactory
{
public:
    vector<IUserInput *> readersList;
    vector<IUserOutput *> writersList;
    IUserInput *getReader(InputServiceType inputType)
    {
        // States are integers to support more types in the future
        if (inputType == IST_Keyboard)
        {
            /*
             * The new Keyword createsthe object on the heap,
             * thus the memory is occupied untill manual deletion of the object
             */
            return new Keyboard();
        }
        else if (inputType == IST_FileInput)
        {
            return new FileReader("./input.txt");
        }
        return NULL;
    }
    IUserOutput *getWriter(OutputServiceType outputType)
    {
        IUserOutput *writerService = nullptr;
        // States are integers to support more types in the future
        if (outputType == OST_Monitor)
        {
            /*
             * The new Keyword creates the object on the heap,
             * thus the memory is occupied untill manual deletion of the object
             */
            writerService = new Monitor();
        }
        else if (outputType == OST_FileOutput)
        {
            writerService = new FileWriter("./input.txt");
        }

        this->writersList.push_back(writerService);
        return writerService;
    }
    // handles the responsibility of lifecycle management
    ~ServiceFactory()
    {
        for(auto writerService: writersList)
        {
            if(writerService != nullptr)
            {
                delete writerService;
            }
        }
    }
};