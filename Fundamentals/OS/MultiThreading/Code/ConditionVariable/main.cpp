#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

int main()
{
    cout << "Main thread: Enter\n";
    std::mutex gMutex;
    std::condition_variable gConditionVariable;
    int sharedResource = 0;
    bool completionNotifier = false;
    
    std::thread thread1([&]
                        {
                            cout << "thread1: ENTER\n";
                            std::unique_lock lock(gMutex);
                            if (!completionNotifier)
                            {
                                // thread goes into sleep, and when it wakes up it starts executing from this point;
                                // release lock auto matically
                                cout << "thread1: SLEEP\n";
                                gConditionVariable.wait(lock);
                                // wake up and aquire lock
                            }

                            // critical section
                            sharedResource += 1;

                            cout << "thread1: END\n";
                            // lock released automatically
                        });
    std::thread thread2([&]
                        {
                            cout << "thread2: ENTER\n";
                            std::unique_lock lock(gMutex);
                            ;
                            // critical section
                            this_thread::sleep_for(3000ms);
                            sharedResource += 1;

                            // notify sleeping threads to complete their exec
                            completionNotifier = 1;
                            gConditionVariable.notify_one();
                            cout << "thread2: END\n";
                            // release lock auto matically
                        });
    thread1.join();
    thread2.join();
    cout << "computed result : " << sharedResource << "\n";
    cout << "Main thread: END\n";
}