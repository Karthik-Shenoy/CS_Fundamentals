#include<iostream>
#include "Graph.h"
#include "./iterators/GraphIterator.h"
#include "./iterators/GraphBFSIterator.h"
using namespace std;


int main(){
    Graph<string> *graph = new Graph<string>();

    bool isBFS;
    cout << "choose iterator \n0.DFS\n1.BFS\n;";
    cin >> isBFS;
    
    IIterator *gIter = new GraphIterator<string>(graph);
    if(isBFS){
        gIter = new GraphBFSIterator<string>(graph);
    }
    
    cout << "\n";
    while(gIter->hasMore()){
        gIter = gIter->moveNext();
        if(!gIter)
            break;
        gIter->display();
    }
    cout << "exited sucessfully" << "\n";
    return 0;
}