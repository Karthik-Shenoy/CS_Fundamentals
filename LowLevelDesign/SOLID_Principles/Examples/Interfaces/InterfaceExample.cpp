#include <iostream>
using namespace std;

int g_isFileOpen = false;



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
        if(!g_isFileOpen){
            cout << "opening the file : " << path << "\n";
            g_isFileOpen = true;
        }
    }
    void read()
    {
        cout << "reading from the file....\n";
    }
};

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
        if(!g_isFileOpen){
            cout << "opening the file : " << path << "\n";
            g_isFileOpen = true;
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


/*
------------------------------------------------------------
User Service Module
------------------------------------------------------------
*/

class User
{
private:
    IUserInput *ReaderService;
    IUserOutput *WriterService;
    IUserInput *getReader(int state)
    {
        if (state)
        {
            /*
             * The new Keyword createsthe object on the heap,
             * thus the memory is occupied untill manual deletion of the object
             */
            return new Keyboard();
        }
        else
        {
            return new FileReader("./input.txt");
        }
    }
    IUserOutput *getWriter(int state)
    {
        if (state)
        {
            /*
             * The new Keyword createsthe object on the heap,
             * thus the memory is occupied untill manual deletion of the object
             */
            return new Monitor();
        }
        else
        {
            return new FileWriter("./input.txt");
        }
    }

public:
    User(int ReaderState, int WriterState)
    {
        ReaderService = getReader(ReaderState);
        WriterService = getWriter(WriterState);
    }
    void read()
    {
        ReaderService->read();
    }
    void write()
    {
        WriterService->write();
    }
};

int main()
{
    int r_state, w_state;
    cout << "Enter reader and writer devices : \n";
    cin >> r_state >> w_state;
    User *user = new User(r_state, w_state);
    user->read();
    user->write();
}
