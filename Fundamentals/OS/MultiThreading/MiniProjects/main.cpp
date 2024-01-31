#include<iostream>
#include "DataReversalService.h"
using namespace std;

int main()
{
    DataReversalService* drs = new DataReversalService();
    short choice = 0;
    cout << "choose the calc operation : \n";
    cout << "1. Single Threaded \n2. Multithreaded \n3. Optimized Multi Threaded\n";
    cin >> choice;

    auto startTime = chrono::high_resolution_clock::now();

    // operations
    if(choice == 1)
        drs->calc();
    else if(choice == 2)
        drs->multiThreadedCalc();
    else 
        drs->optimizedMultiThreadedCalc();

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime-startTime);
    cout << duration.count() << "\n"; 
    cout << "\n Checking Validity ...";
    if(!drs->checkFileCollectionValidity())
        cout << "Operation Produced Invalid Results\n";
}