#pragma once
class GlobalState
{
private:
    bool bIsFileOpen = false;
    static GlobalState *instance;

public:
    bool isFileOpen()
    {
        return bIsFileOpen;
    }
    void openFile()
    {
        bIsFileOpen = true;
    }
    static GlobalState *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new GlobalState();
        }
        return instance;
    }
};
//Initialization of the static type
GlobalState* GlobalState::instance = nullptr; 