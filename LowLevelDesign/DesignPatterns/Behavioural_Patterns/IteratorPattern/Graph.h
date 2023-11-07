#pragma once
#include<vector>
#include<map>
using namespace std;

template <class T> class Node{
private:
    vector<Node<T>*> adjList;
public:
    T data;
    Node(T data)
    {
        this->data = data;
    }
    void addNeighbor(Node<T> *neighbor)
    {
        adjList.push_back(neighbor);
    }
    vector<Node<T>*> getNeighbors(){
        return adjList;
    }
};

template <class T> class Graph {
public:
    int nEdges;
    map<T, Node<T>*> nodes;
    Graph()
    {
        cout << "enter the number of edges : ";
        cin >> nEdges;
        cout << "enter the edges Node(u) ---> Node(v) : \n";
        for(int i = 0; i < nEdges; i++){
            T u_data, v_data;
            cin >> u_data >> v_data;
            Node<T> *u_node = nodes.find(u_data) == nodes.end() ? new Node(u_data) : nodes[u_data];
            Node<T> *v_node = nodes.find(v_data) == nodes.end() ? new Node(v_data) : nodes[v_data];
            // update nodes in the graph
            nodes[u_data] = u_node; 
            nodes[v_data] = v_node;
            u_node->addNeighbor(v_node);
        }
    }

    // consumes extra space
    vector<Node<T>*> getNodeList(){
        vector<Node<T>*> nodeList;
        // typename is used to specify that the iterator is a type to avoid compiler getting confused
        for(typename map<T, Node<T>*>::iterator it = nodes.begin(); it != nodes.end(); it++)
        {
            nodeList.push_back(it->second);
        }
        return nodeList;
    }

    map<T, Node<T>*>* getNodeMap(){
        return &nodes;
    }

    ~Graph(){
        // delete all the nodes in the graph or else they will cause a memory leak
    }

};


