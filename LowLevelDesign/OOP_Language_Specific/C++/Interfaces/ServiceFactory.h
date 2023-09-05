#pragma once
#include "InputServices.h"
#include "OutputServices.h"
#include "Types.h"

/*
------------------------------------------------------------
Service Factory Module
------------------------------------------------------------
*/

class ServiceFactory
{
public:
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
        else if(inputType == IST_FileInput)
        {
            return new FileReader("./input.txt");
        }
        return NULL;
    }
    IUserOutput *getWriter(OutputServiceType outputType)
    {
        // States are integers to support more types in the future
        if (outputType == OST_Monitor)
        {
            /*
             * The new Keyword createsthe object on the heap,
             * thus the memory is occupied untill manual deletion of the object
             */
            return new Monitor();
        }
        else if(outputType == OST_FileOutput)
        {
            return new FileWriter("./input.txt");
        }
        return NULL;
    }
};