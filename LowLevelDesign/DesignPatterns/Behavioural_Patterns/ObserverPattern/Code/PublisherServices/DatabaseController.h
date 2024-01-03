#pragma once
#include <string>
#include <shared_mutex>
#include <iostream>
#include <thread>
using namespace std;

struct Record
{
    string account_id;
    int balance;
    shared_mutex read_write_lock;
};

class DatabaseController
{
private:
    int num_records;
    Record database[100];
    int reader_count = 0;
    int writer_count = 0;

    // static pointers need to be initialized after including them in a separate file
    static DatabaseController *DatabaseController_instance;

    DatabaseController()
    {
        num_records = 3;
        database[0].account_id = "ACN_1";
        database[0].balance = 20000;

        database[1].account_id = "ACN_2";
        database[1].balance = 10000;

        database[2].account_id = "ACN_3";
        database[2].balance = 15000;
    }

public:
    // singleton pattern [not thread safe]
    static DatabaseController *getInstance()
    {
        if (DatabaseController::DatabaseController_instance == nullptr)
        {
            cout << 1 << endl;
            DatabaseController::DatabaseController_instance = new DatabaseController();
        }
        return DatabaseController::DatabaseController_instance;
    }

    void read(string account_id)
    {
        for (int i = 0; i < this->num_records; i++)
        {
            if (database[i].account_id == account_id)
            {
                using namespace std::chrono_literals;

                shared_lock sharedLock(database[i].read_write_lock);
                this->reader_count += 1;
                cout << "Num Readers : " << this->reader_count << "\n";
                this_thread::sleep_for(2000ms);
                this->reader_count -= 1;
            }
        }
    }
    void update(string account_id, int new_balance)
    {
        for (int i = 0; i < this->num_records; i++)
        {
            if (database[i].account_id == account_id)
            {
                unique_lock uniqueLock(database[i].read_write_lock);
                this->writer_count += 1;
                cout << "Num Writers : " << this->writer_count << "\n";
                this_thread::sleep_for(2000ms);
                database[i].balance = new_balance;
                this->writer_count-= 1;
            }
        }
    }
    ~DatabaseController()
    {
        delete DatabaseController::DatabaseController_instance;
    }
};