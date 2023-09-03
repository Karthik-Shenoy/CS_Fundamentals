#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int sharedData = 0;

/*
    Unsafe functions as critical section wont be mutually exclusive to the threads in case of
    pre-emption by the Scheduling Alogrithm
    1s == 1e8 ops
    (1/10)s = 1e7 ops
*/
void updateSharedData(int x)
{
    /*
     * Critical section (non-atomic operation)
     * temp = sharedData + x ---> preemption can occur after this operation
     * sharedData = temp
     */
    sharedData += x; // Preemption might occur because of long-ops
    // ---END---
}

void Unsafe_UI_operation(int life_time)
{
    for (int i = 0; i < life_time; i++)
    {
        // Critical section (non-atomic operation)
        updateSharedData(5);
        // ---END---
        if (i % (int)1e7 == 0)
            cout << "UI_Thread\n";
    }
}

void Unsafe_WorkerOperation(int life_time)
{
    for (int i = 0; i < life_time; i++)
    {
        // Critical section (non-atomic operation)
        updateSharedData(-2);
        // ---END---
        if (i % (int)1e7 == 0)
            cout << "Worker_Thread\n";
    }
}

/*
    Safe functions as critical section will be mutually exclusive to the threads in case of
    pre-emption by the processor
*/
mutex m;
void Safe_updateSharedData(int x)
{
    // Critical section (non-atomic operation)
    m.lock();
    sharedData += x; // mutex prevents the other thread from entering the critical section
    m.unlock();
    // ---END---
}

void Safe_UI_operation(int life_time)
{
    for (int i = 0; i < life_time; i++)
    {
        // Critical section (non-atomic operation)
        Safe_updateSharedData(5);
        // ---END---
        if (i % (int)1e7 == 0)
            cout << "UI_Thread\n";
    }
}

void Safe_WorkerOperation(int life_time)
{
    for (int i = 0; i < life_time; i++)
    {
        // Critical section (non-atomic operation)
        Safe_updateSharedData(-2);
        // ---END---
        if (i % (int)1e7 == 0)
            cout << "Worker_Thread\n";
    }
}

void normalExecution()
{
    Unsafe_UI_operation(1e8);
    Unsafe_WorkerOperation(3 * 1e7);
    cout << sharedData << "\n";
}

void unsafeParallelExecution()
{
    sharedData = 0;
    thread WorkerThread(Unsafe_WorkerOperation, 3 * 1e7);
    Unsafe_UI_operation(1e8);
    WorkerThread.join();
    cout << sharedData << "\n";
}

void threadSafeParallelExecution()
{
    sharedData = 0;
    thread WorkerThread(Safe_WorkerOperation, 3 * 1e7);
    Safe_UI_operation(1e8);
    WorkerThread.join();
    cout << sharedData << "\n";
}

int main()
{
    cout << "------------------------\n";
    cout << "Normal Execution\n";
    cout << "------------------------\n";

    normalExecution();
    cout << "------------------------\n";
    cout << "Parallel Execution\n";
    cout << "------------------------\n";

    unsafeParallelExecution();
    cout << "------------------------\n";
    cout << "Safe Parallel Execution\n";
    cout << "------------------------\n";

    threadSafeParallelExecution();
}