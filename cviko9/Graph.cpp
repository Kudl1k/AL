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
    for (int i = 0; i < nodes.size(); ++i) {
        nodes[i]->visited = false;
    }
}

vector<int> Graph::SourceRemoval()
{
    Init(); // Initialize the graph

    queue<Node*> q;
    vector<int> solution;

    // Add all nodes with zero indegree to the queue
    for (Node* nod : nodes)
    {
        if (nod->indegree == 0)
        {
            q.push(nod);
            nod->visited = true; // Mark as visited
        }
    }

    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        solution.push_back(curr->value); // Add node to the solution

        // Update the indegree of neighbors
        for (Node* neighbor : curr->neighbours)
        {
            neighbor->indegree--;

            if (neighbor->indegree == 0 && !neighbor->visited)
            {
                q.push(neighbor);
                neighbor->visited = true;
            }
        }
    }

    return solution;
}