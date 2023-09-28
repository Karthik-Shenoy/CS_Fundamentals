#include<iostream>
#include "Graph.h"
#include "./iterators/GraphIterator.h"
using namespace std;


int main(){
    Graph<string> *graph = new Graph<string>();
    IIterator *gIter = new GraphIterator<string>(graph);
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