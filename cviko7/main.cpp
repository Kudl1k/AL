#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char  **argv)
{
    cout << "------------------------------------------------------" << endl;
    cout << "Pruchod prvnim grafem do hloubky rekurzivne pocinaje vrcholem 0:" << endl;
    cout << "------------------------------------------------------" << endl;
    Graph g1(argv[1]);
    g1.DepthFirstRecursive(0);
    cout << endl;

    cout << "------------------------------------------------------" << endl;
    cout << "Pruchod prvnim grafem do hloubky iterativne pocinaje vrcholem 0:" << endl;
    cout << "------------------------------------------------------" << endl;
    g1.DepthFirstIterative(0);
    cout << endl;

    cout << "------------------------------------------------------" << endl;
    cout << "Pruchod prvnim grafem do sirky pocinaje vrcholem 0:" << endl;
    cout << "------------------------------------------------------" << endl;
    g1.BreadthFirst(0);
    cout << "------------------------------------------------------" << endl;

    cout << "Sousedi se vzdalenosti jsou: " ;
    for (int ver : g1.GetNodesWithGivenDistance(0, 3))
        cout << ver << " ";
    cout << endl;

    int poradi = 1;
    for (int sum : g1.ComponentSums())
        cout<<poradi++<<". komponenta, soucet je: " << sum << endl;

}