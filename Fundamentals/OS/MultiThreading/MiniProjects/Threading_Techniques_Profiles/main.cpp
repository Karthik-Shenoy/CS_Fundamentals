#include <iostream>
#include "DataReversalService.h"
using namespace std;

int main()
{
    DataReversalService *drs = new DataReversalService();
    short choice = 0;
    short poolSize = 5;
    cout << "choose the calc operation : \n";
    cout << "1. Single Threaded \n2. Multithreaded \n3. Optimized Multi Threaded\n4. Thread Pool Based\n";
    cin >> choice;

    if(choice == 4)
    {
        cout << "Pool size ? :";
        cin >> poolSize;
    }

    auto startTime = chrono::high_resolution_clock::now();

    // the following tasks are executed sequentially (if called sequentially)
    // as we wait for all threads to join, before starting with the new task
    if (choice == 1)
        drs->calc();
    else if (choice == 2)
        drs->multiThreadedCalc();
    else if (choice == 3)
        drs->overOptimizedMultiThreadedCalc();
    else
    {
        drs->threadPoolCalc(poolSize);
    }
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    cout << duration.count() << "ms\n";
    cout << "\nChecking Validity ...\n";
    if (!drs->checkFileCollectionValidity())
        cout << "Operation Produced Invalid Results\n";
}