#pragma once
#include "../Graph.h"
#include "IIterator.h"
#include "vector"
#include "map"
#include <iostream>

template <class T>
class GraphBFSIterator : public IIterator
{
    // Concrete Collection
    Graph<T> *m_pGraph;

    // data structures for traversal
    vector<Node<T> *> nodeList;
    map<T, bool> visited;
    Node<T> *pNodeQueue[100];
    Node<T> *currentNode = nullptr;
    int front = 0, tail = -1, nodeIndex = 0;

    // iterators pointer to curr node in the collection

public:
    GraphBFSIterator(Graph<T> *pGraph)
    {
        this->m_pGraph = pGraph;
        this->nodeList = m_pGraph->getNodeList();
    }
    IIterator *moveNext()
    {
        cout << "node Index : " << nodeIndex << "\n";
        if (!currentNode)
        {
            if (!nodeList.size())
                return NULL;

            this->currentNode = this->nodeList[this->nodeIndex++];
            while (visited[this->currentNode->data] && this->nodeList.size())
            {
                this->currentNode = nodeList[this->nodeIndex++];
            }

            visited[currentNode->data] = true;
            return this;
        }
        else
        {
            for (Node<T> *neighbor : this->currentNode->getNeighbors())
            {
                if (!visited[neighbor->data])
                {
                    visited[neighbor->data] = true;
                    this->pNodeQueue[++tail] = neighbor;
                }
            }
            if (front <= tail)
            {
                this->currentNode = this->pNodeQueue[front++];
            }
            else
            {
                if (nodeIndex == this->nodeList.size())
                    return nullptr;
                this->currentNode = this->nodeList[nodeIndex++];
                while (visited[this->currentNode->data] && nodeIndex < this->nodeList.size())
                {
                    this->currentNode = this->nodeList[nodeIndex++];
                }

                visited[this->currentNode->data] = true;
                // all nodes have been visited
                if (nodeIndex == this->nodeList.size())
                    return nullptr;
            }
            return this;
        }
    }
    bool hasMore()
    {
        return this->nodeIndex < this->nodeList.size();
    }
    void display()
    {
        cout << this->currentNode->data << "\n";
    }
};