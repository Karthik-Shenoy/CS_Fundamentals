#pragma once
#include<iostream>
#include<map>
#include<vector>
#include <cstdlib> 
#include <string>
using namespace std;

/* Mimics in-memory single level file collection using maps*/
class FileCollection {
    map<string, map<string, string>> FileStructure;
public:  
    void writeFileData(string folderName, string fileName, string data)
    {
        FileStructure[folderName][fileName] = data;
    }
    string readFileData(string folderName, string fileName)
    {
        if(!FileStructure.count(folderName) || !FileStructure[folderName].count(fileName))
            return "";
        return FileStructure[folderName][fileName];
    }
    void populateFiles()
    {
        const int FOLDER_LENGTH = 100;
        const int FILE_COUNT = 1000;
        
        // populate 700 files in the structure
        for(int fileNum = 0; fileNum < FILE_COUNT; fileNum++)
        {
            int folderNum = rand() % FOLDER_LENGTH;
            string data = "123456", fileName = "File"+to_string(fileNum), folderName = "Folder"+to_string(folderNum);
            this->writeFileData(folderName, fileName, data);
        }
        cout << "Files Populated Successfully !\n";
    }
    vector<string> getFoldersList()
    {
        vector<string> foldersList;
        for(pair<string, map<string, string>> folderData: this->FileStructure)
        {
            string folderName = folderData.first;
            foldersList.push_back(folderName);
        }
        return foldersList;
    }
    vector<string> getFilesList(string folderName)
    {
        vector<string> fileList;
        for(auto fileData: this->FileStructure[folderName])
        {
            fileList.push_back(fileData.first);
        }
        return fileList;
    }
};