#include <iostream>
#include "GraphInMatrix.h"

using namespace std;

int main(int argc, char **argv)
{
    GraphInMatrix g(argv[1]);

    //vytvoření grafu v kodu
    //GraphInMatrix g(6);
    //g.AddEdge(0,2);
    //g.AddEdge(1,2);
    //g.AddEdge(3,2);
    //g.AddEdge(4,2);
    //g.AddEdge(5,2);

    g.ReportMatrix();
    g.ReportEdges();

    g.ReportDegrees();
    g.ReportNeighbours();
    cout << g.IsComplete() << endl;
    cout << g.IsStar() << endl;
}