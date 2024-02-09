#include <thread>
#include <functional>
#include <queue>
#include <mutex>
#include <iostream>
#include <condition_variable>
using namespace std;


int GLOBAL_COUNT = 0;
class ReversalTask
{
private:
    function<void(string, string, string)> functor;
    string arg1;
    string arg2;
    string arg3;

public:
    ReversalTask(function<void(string, string, string)> functor, string arg1, string arg2, string arg3)
    {
        this->functor = functor;
        this->arg1 = arg1;
        this->arg2 = arg2;
        this->arg3 = arg3;
    }
    void run()
    {
        this->functor(this->arg1, this->arg2, this->arg3);
    }
};

class ThreadPool
{
private:
    queue<ReversalTask *> jobQueue;
    mutex queueMutex;
    condition_variable conditionVariableNotif;
    bool shouldTerminate = false;
    vector<thread> threadsList;

    // Execution Controls
    mutex ExecutionMutex;
    condition_variable ExecutionNotifier;

    void threadLoop()
    {
        while (true)
        {
            ReversalTask *job;
            {
                unique_lock<mutex> lock(queueMutex);
                conditionVariableNotif.wait(lock, [this]
                                            { return this->shouldTerminate || !this->jobQueue.empty(); });
                if (this->shouldTerminate)
                {
                    // cout << "Terminating Thread...\n";
                    ExecutionNotifier.notify_one();
                    return;
                }
                job = jobQueue.front();
                jobQueue.pop();
            }
            job->run();
            
            ExecutionNotifier.notify_one();
        }
    }

public:
    void queueOperation(ReversalTask *task)
    {
        {
            lock_guard<mutex> lock(queueMutex);
            jobQueue.push(task);
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
        cout << "Thread pool destroyed ! \n";
    }
    ~ThreadPool()
    {
        while (true)
        {
            unique_lock<mutex> lock(ExecutionMutex);
            ExecutionNotifier.wait(lock, [this] {return this->jobQueue.empty(); });
            if (jobQueue.empty())
            {
                this->stop();
                return;
            }
        }
    }
};