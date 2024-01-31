#include <thread>
#include <functional>
#include <queue>
#include <mutex>
#include <iostream>
#include <condition_variable>
using namespace std;

mutex ExecutionMutex;
condition_variable ExecutionNotifier;

class ThreadPool
{
private:
    queue<function<void()>> jobQueue;
    mutex queueMutex;
    condition_variable conditionVariableNotif;
    bool shouldTerminate = false;
    vector<thread> threadsList;
    void threadLoop()
    {
        while (true)
        {
            function<void()> job;
            {
                unique_lock<mutex> lock(queueMutex);
                conditionVariableNotif.wait(lock, [this]
                                            { return this->shouldTerminate || !this->jobQueue.empty(); });

                if (this->shouldTerminate)
                {
                    cout << "Terminating...\n";
                    return;
                }
                job = jobQueue.front();
                jobQueue.pop();
            }
            job();
            ExecutionNotifier.notify_one();
        }
    }

public:
    void queueOperation(function<void()> func)
    {
        {
            lock_guard<mutex> lock(queueMutex);
            jobQueue.push(func);
        }
        this->conditionVariableNotif.notify_one();
    }

    void start(int poolSize)
    {
        while (poolSize)
        {
            // spawn threads that will perform the tasks
            this->threadsList.push_back(thread(&threadLoop, this));
            poolSize--;
        }
    }
    void stop()
    {
        {
            lock_guard<mutex> lock(queueMutex);
            this->shouldTerminate = true;
        }
        conditionVariableNotif.notify_all();
        for (std::thread &active_thread : threadsList)
        {
            active_thread.join();
        }
        threadsList.clear();
    }
    ~ThreadPool()
    {
        while(true)
        {
            unique_lock<mutex> lock(ExecutionMutex);
            ExecutionNotifier.wait(lock, [this]{return this->jobQueue.empty();});
            
            if(jobQueue.empty())
            {
                this->stop();
                return;
            }
        }
    }
};

int main()
{
    auto oper = []()
    {
        this_thread::sleep_for(100ms);
        cout << this_thread::get_id() << "\n";
    };
    ThreadPool tp;
    tp.start(10);
    for (int i = 0; i < 10; i++)
    {
        tp.queueOperation(oper);
    }
}