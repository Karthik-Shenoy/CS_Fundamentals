#pragma once
#include <iostream>
#include "GlobalState.h"
using namespace std;

/*
------------------------------------------------------------
Output Services Module
------------------------------------------------------------
*/

class IUserOutput
{
public:
    virtual void write() = 0;
};


class FileWriter : public IUserOutput
{
public:
    FileWriter(string path)
    {
        if(!GlobalState::getInstance()->isFileOpen()){
            cout << "opening the file : " << path << "\n";
            GlobalState::getInstance()->openFile();
        }
        else{
            cout << "using the already opened file \n";
        }
    }
    void write()
    {
        cout << "Writing to the file....\n";
    }
};

class Monitor : public IUserOutput
{
public:
    Monitor()
    {
        cout << "Monitor Driver Initialized....\n";
    }
    void write()
    {
        cout << "Writing to the Monitor Display....\n";
    }
};
