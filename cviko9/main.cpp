#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char **argv)
{

    Graph g1(argv[1]);
    for (int num : g1.SourceRemoval())
        cout<<num<<" ";
    cout << endl;

}