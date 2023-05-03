#include <iostream>
#include "GraphInMatrix.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "--------------------------------------------------------------" << endl;
    cout << "Demonstrace generovani permutaci" << endl;
    cout << "Vsechny mozne permutace cisel 1,2,3,4 jsou nasledujici:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (auto vec : Permutations(vector<int>{1, 2, 3, 4}))
    {
        for (int num : vec)
            cout << num << " ";
        cout << endl;
    }
    cout << "--------------------------------------------------------------" << endl;

    cout << "Report vazeneho grafu:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    GraphInMatrix g(argv[1]);

    g.ReportMatrix();
    g.ReportEdges();

    g.ReportDegrees();
    g.ReportNeighbours();

    cout <<"Je graf kompletni?: " << g.IsComplete() << endl;

    cout << "--------------------------------------------------------------" << endl;
    cout << "Reseni problemu obchodniho cestujicicho:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    g.PrintShortestPath(0);
    cout << "--------------------------------------------------------------" << endl;




}