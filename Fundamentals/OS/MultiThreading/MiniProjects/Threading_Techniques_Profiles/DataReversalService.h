#pragma once
#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include "./ThreadPool/ThreadPool.h"
#include "./Collections/FileCollection.h"

using namespace std;

class DataReversalService
{
    FileCollection *fc = nullptr;
public:
    DataReversalService()
    {
        fc = new FileCollection();
        fc->populateFiles();
    }
    string longReverseOperation(string str)
    {
        // Long Ops (50ms per reversal) => 50 * 100 = 5000ms
        this_thread::sleep_for(50ms);
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
        {
            char temp = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = temp;
        }
        return str;
    }
    void longReverseOperationWithWrite(string folderName, string fileName, string str)
    {
        this_thread::sleep_for(50ms);
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
        {
            char temp = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = temp;
        }
        fc->writeFileData(folderName, fileName, str);
    }

    bool checkFolderValidity(string folderName)
    {
        const string validValue = "654321";
        vector<string> fileList = fc->getFilesList(folderName);
        for (auto file : fileList)
        {
            string fileData = fc->readFileData(folderName, file);
            if (fileData != validValue)
            {
                cout << folderName << "/" << file << " : " << fileData << "\n";
                return false;
            }
        }
        return true;
    }

    bool checkFileCollectionValidity()
    {
        vector<string> foldersList = this->fc->getFoldersList();
        for (auto folderName : foldersList)
        {
            if (!(this->checkFolderValidity(folderName)))
                return false;
        }
        return true;
    }

    void processFolder(string folderName)
    {
        vector<string> fileList = fc->getFilesList(folderName);

        for (auto file : fileList)
        {
            string reversedFileData = longReverseOperation(fc->readFileData(folderName, file));
            fc->writeFileData(folderName, file, reversedFileData);
        }
    }

    void processFolderMultiThreaded(string folderName)
    {
        vector<string> fileList = fc->getFilesList(folderName);
        vector<thread> threadsList;
        for (auto file : fileList)
        {
            threadsList.push_back(thread(&longReverseOperationWithWrite, this, folderName, file, fc->readFileData(folderName, file)));
        }
        for (auto &thread : threadsList)
        {
            thread.join();
        }
    }

    void processFolderThreadPool(string folderName, ThreadPool *threadPool)
    {
        vector<string> fileList = fc->getFilesList(folderName);
        for (string &fileName : fileList)
        {
            std::function<void(std::string, std::string, std::string)> boundFunction =
                std::bind(&longReverseOperationWithWrite, this,
                          std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

            string fileData = fc->readFileData(folderName, fileName);

            ReversalTask *task = new ReversalTask(boundFunction, folderName, fileName, fileData);
            threadPool->queueOperation(task);
        }
    }

    void calc()
    {
        vector<string> foldersList = this->fc->getFoldersList();
        cout << "\nStarting Reversal Process\n\n";
        for (string folderName : foldersList)
        {
            this->processFolder(folderName);
        }
        cout << "Processing Complete"
             << "\n";
    }

    void multiThreadedCalc()
    {
        vector<string> foldersList = this->fc->getFoldersList();
        cout << "\nStarting MultiThreaded Reversal Process\n\n";
        vector<thread> threadList;
        // binding this with the function running on a separate thread
        for (string folderName : foldersList)
        {
            threadList.push_back(thread(&processFolder, this, folderName));
        }
        for (int i = 0; i < threadList.size(); i++)
        {
            threadList[i].join();
        }
        cout << "Processing Complete"
             << "\n";
    }

    void overOptimizedMultiThreadedCalc()
    {
        vector<string> foldersList = this->fc->getFoldersList();
        cout << "\nStarting over Optimized Multi Threaded Reversal Process\n\n";
        for (string folderName : foldersList)
        {
            this->processFolderMultiThreaded(folderName);
        }
        cout << "Processing Complete"
             << "\n";
    }

    void threadPoolCalc(short poolSize)
    {
        // can not allocate on stack
        ThreadPool *threadPool = new ThreadPool;

        vector<string> foldersList = this->fc->getFoldersList();
        cout << "\nStarting Thread Pool based Reversal Process\n\n";
        // binding this with the function running on a separate thread
        for (string folderName : foldersList)
        {
            processFolderThreadPool(folderName, threadPool);
        }

        threadPool->start(poolSize);

        cout << "Processing Complete"
             << "\n";

        // thread pool destructor is called (wait for execution of the threads)
        delete threadPool;
    }
};