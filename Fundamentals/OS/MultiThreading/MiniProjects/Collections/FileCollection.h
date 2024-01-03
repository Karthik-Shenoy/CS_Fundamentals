#pragma once
#include<iostream>
#include<map>
#include<vector>
#include <cstdlib> 
using namespace std;

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
        const int FOLDER_LENGTH = 7;
        
        for(int fileNum = 0; fileNum < 100; fileNum++)
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
            cout << folderName << "\n";
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