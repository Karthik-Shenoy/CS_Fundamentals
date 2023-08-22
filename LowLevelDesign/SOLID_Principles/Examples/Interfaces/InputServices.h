#pragma once
#include <iostream>
#include "GlobalState.h"
using namespace std;

/*
------------------------------------------------------------
Input Services Module
------------------------------------------------------------
*/
class IUserInput
{
public:
    virtual void read() = 0;
};


class Keyboard : public IUserInput
{
public:
    Keyboard()
    {
        cout << "Keyboard Drivers Initialized.\n";
    }
    void read()
    {
        cout << "reading from the Keyboard....\n";
    }
};

class FileReader : public IUserInput
{
public:
    FileReader(string path)
    {
        if(GlobalState::getInstance()->isFileOpen()){
            cout << "opening the file : " << path << "\n";
            GlobalState::getInstance()->openFile();
        }
    }
    void read()
    {
        cout << "reading from the file....\n";
    }
};