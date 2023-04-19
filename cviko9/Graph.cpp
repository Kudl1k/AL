#include "Graph.h"

Graph::Graph(string path)
{
    ifstream soubor(path);

    int nodescount;
    soubor >> nodescount;

    Node* newNode;
    for (int i = 0; i < nodescount; i++)// pro kazdy vrchol dynamicky vytvorim Node a vlozim do vektoru
    {
        newNode = new Node; //vytvoreni uzlu
        newNode->value = i;
        newNode->indegree = 0;
        nodes.push_back(newNode); //na indexu i bude vrchol s hodnotou i
    }

    int val1, val2;
    while (!soubor.eof())
    {
        soubor >> val1 >> val2;
        nodes[val1]->neighbours.push_back(nodes[val2]);
    }

    soubor.close();
}

Graph::~Graph()
{
    for (Node* nod : nodes)
        delete nod;
}

void Graph::Init()
{

}

vector<int> Graph::SourceRemoval()
{
    Init();
    vector<int> solution;

    return solution;
}