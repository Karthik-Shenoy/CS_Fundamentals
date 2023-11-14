#include<iostream>
#include<cstdlib>
#include<time.h>
#include<mutex>
#include<thread>
#include<vector>
using namespace std;

class Resource {
private:
    int data = 0;
    mutex mutexLock;
public:
    void acquireLock(int threadIdx, int resourceIndex)
    {
        cout << "Thread : " << threadIdx << " Wants Lock on " << resourceIndex << endl;
        this->mutexLock.lock();
        cout << "Thread : " << threadIdx << " acquired Lock on " << resourceIndex << endl;
    }
    void releaseLock(int threadIdx, int resourceIndex)
    {
        this->mutexLock.unlock();
        cout << "Thread : " << threadIdx << " released " << resourceIndex << endl;
    }
    void update()
    {
        this->data++;
    }

};

static Resource gResources[3];
int makeSafe = 0;
/**
  * the following function will lead to deadlock most of the time
  * as the locks on resources are getting acquired in a random order
  * which might lead to circular dependency
  */ 
void threadOperation(int threadIdx)
{
    using namespace std::chrono_literals;
    while(1)
    {
        srand(time(0));
        int resourceIndex1 = rand() % 3, resourceIndex2 = rand() % 3;
        if(resourceIndex1 == resourceIndex2)
            continue;

        if(makeSafe && resourceIndex1 > resourceIndex2)
        {
            swap(resourceIndex1, resourceIndex2);
        }

        gResources[resourceIndex1].acquireLock(threadIdx, resourceIndex1);
        gResources[resourceIndex2].acquireLock(threadIdx, resourceIndex2);

        gResources[resourceIndex1].update();
        gResources[resourceIndex2].update();

        this_thread::sleep_for(1000ms);

        gResources[resourceIndex2].releaseLock(threadIdx, resourceIndex2);
        gResources[resourceIndex1].releaseLock(threadIdx, resourceIndex1);

        this_thread::sleep_for(500ms);
    }
}
int main()
{
    vector<thread> threads;
    cout << "Press 1 for safe thread operation and 0 for unsafe thread ops" << endl;
    cin >> makeSafe;
    for(int i = 0; i < 6; i++)
    {
        threads.push_back(thread(&threadOperation, i+1));
    }
    for(int i = 0; i < 6; i++)
    {
        threads[i].join();
    }
    return 0;
}