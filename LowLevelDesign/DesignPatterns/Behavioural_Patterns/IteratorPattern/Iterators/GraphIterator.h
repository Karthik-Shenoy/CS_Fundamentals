#pragma once
#include "../Graph.h"
#include "./IIterator.h"
#include<iostream>
#include<string>
#include<stack>
using namespace std;

template <class T>
class GraphIterator: public IIterator {
private:
    // Concrete collection
    Graph<T> *graph;

    // datastructures required for iteration
    map<T, bool> visited;
    vector<Node<T>*> nodeList;
    stack<Node<T>*> nodeStack;

    // iterators pointer to curr node in the collection
    Node<T> *currNode = NULL;
    int index = 0;

public:
    GraphIterator(Graph<T> *graph){
        this->graph = graph;
        nodeList = graph->getNodeList();
        cout << "nodeList : \n";
        for(Node<T>* x: nodeList)
            cout << x->data << ' ';
    }   
    IIterator* moveNext(){
        if(!currNode){

            if(!nodeList.size())
                return NULL;
            currNode = nodeList[index++];
            while(visited[currNode->data]){
                currNode = nodeList[index++];
            }
            visited[currNode->data] = true;
            return this;

        } else {
            for(auto neighbor: currNode->getNeighbors()){
                if(!visited[neighbor->data]){
                    visited[neighbor->data] = true;
                    nodeStack.push(neighbor);
                }
            }
            if(nodeStack.size())
            {
                currNode = nodeStack.top(); 
                nodeStack.pop();
            } 
            else
            {
                currNode = nodeList[index++];
                while(visited[currNode->data] && index < nodeList.size() ){
                    currNode = nodeList[index++];
                }
                visited[currNode->data] = true;
                if(index == nodeList.size())
                    return NULL;
            }
            return this;
        }
        
        
    };
    bool hasMore(){
        return index != nodeList.size();
    };
    void display(){
        cout << currNode->data << "\n";
    }
};