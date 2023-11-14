#include<iostream>
#include<thread>
#include<vector>
using namespace std;

int main()
{
    auto lambdaFunction = [](int x){
        cout << "function param : " << x << "\n";
        cout << "thread_id : " << this_thread::get_id() << "\n";
    };
    
    // Synchronous execution
    cout << "\n------------------\nSynchronous Execution\n------------------\n";
    vector<thread> threads;
    for(int i = 0; i < 10; i++)
    {
        threads.push_back(thread(lambdaFunction, i));
        threads[i].join();
    }

    // parallel execution using jthreads
    cout << "\n------------------\nParallel Execution\n------------------\n";
    vector<jthread> jthreads;
    for(int i = 0; i < 10; i++)
    {
        jthreads.push_back(jthread(lambdaFunction, i));
    }
}