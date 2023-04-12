#include "Graph.h"

Graph::Graph(string path)
{
    ifstream soubor(path);

    if (!soubor.is_open()){
        cout << "Soubor nelze otevrit!" << endl;
        exit(1);
    }

    int nodescount;
    soubor >> nodescount;

    Node* newNode;
    for (int i = 0; i < nodescount; i++)// pro kazdy vrchol dynamicky vytvorim Node a vlozim do vektoru
    {
        newNode = new Node; //vytvoreni uzlu
        newNode->value = i;
        nodes.push_back(newNode); //na indexu i bude vrchol s hodnotou i
    }

    int val1, val2;
    while (!soubor.eof())
    {
        soubor >> val1 >> val2;
        nodes[val1]->neighbours.push_back(nodes[val2]);
        nodes[val2]->neighbours.push_back(nodes[val1]);
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
    for (Node* nod : nodes)
    {
        nod->state = FRESH;
        nod->distance = -1;
    }
}

void Graph::DepthFirstRecursiveCall(Node* actualNode)
{
    actualNode->state = OPEN;
    cout << "Zpracovan vrchol: " << actualNode->value << endl;
    for (Node* neighbour : actualNode->neighbours)
    {
        if (neighbour->state == FRESH)
            DepthFirstRecursiveCall(neighbour);
    }
    actualNode->state = CLOSED;
}

void Graph::DepthFirstRecursive(int startNumber)
{
    Init();
    Node* startNode = nodes[startNumber];
    DepthFirstRecursiveCall(startNode);
}

void Graph::DepthFirstIterative(int startNumber)
{
    Init();
    stack<Node*> traverseStack;

    Node* startNode = nodes[startNumber];
    startNode->state = OPEN;

    traverseStack.push(startNode);

    while (!traverseStack.empty())
    {
        Node* actual = traverseStack.top();
        traverseStack.pop();
        if (actual->state !=CLOSED)
        {
            cout << "Zpracovan vrchol: " << actual->value << endl;
            actual->state = OPEN;
            for (Node* neighbour : actual->neighbours)
            {
                if (neighbour->state == FRESH)
                    traverseStack.push(neighbour);
            }
            actual->state = CLOSED;
        }
    }
}

void Graph::BreadthFirst(int startNumber)
{
    Init();
    queue<Node*> traverseQueue;

    Node* startNode = nodes[startNumber];
    startNode->state = OPEN;
    startNode->distance = 0;

    traverseQueue.push(startNode);

    while (!traverseQueue.empty())
    {
        Node* actual = traverseQueue.front();
        traverseQueue.pop();

        cout << "Zpracovan vrchol: " << actual->value << " vzdalenost od pocatecniho vrcholu je: " << actual->distance <<"." << endl;
        for (Node* neighbour : actual->neighbours)
        {
            if (neighbour->state == FRESH)
            {
                neighbour->state = OPEN;
                neighbour->distance = actual->distance + 1;
                traverseQueue.push(neighbour);
            }
        }
        actual->state = CLOSED;
    }
}

vector<int> Graph::GetNodesWithGivenDistance(int startNumber, int distance)
{
    vector <int> result;

    Init();
    queue<Node*> traverseQueue;

    Node* startNode = nodes[startNumber];
    startNode->state = OPEN;
    startNode->distance = 0;

    traverseQueue.push(startNode);

    while (!traverseQueue.empty())
    {
        Node* actual = traverseQueue.front();
        traverseQueue.pop();
        if (actual->distance == distance){
            result.push_back(actual->value);
        }
        for (Node* neighbour : actual->neighbours)
        {
            if (neighbour->state == FRESH)
            {
                neighbour->state = OPEN;
                neighbour->distance = actual->distance + 1;
                traverseQueue.push(neighbour);
            }
        }

        actual->state = CLOSED;
    }
    return result;
}


vector<int> Graph::ComponentSums()
{
    vector <int> result;

    Init();
    queue<Node*> traverseQueue;
    for (int i = 0; i < nodes.size(); ++i) {
        Node* startNode = nodes[i];
        startNode->state = OPEN;
        startNode->distance = 0;
        int sum = startNode->value;
        traverseQueue.push(startNode);
        while (!traverseQueue.empty())
        {
            Node* actual = traverseQueue.front();
            traverseQueue.pop();
            sum += actual->value;
            for (Node* neighbour : actual->neighbours)
            {
                if (neighbour->state == FRESH)
                {
                    neighbour->state = OPEN;
                    neighbour->distance = actual->distance + 1;
                    traverseQueue.push(neighbour);
                }
            }
            actual->state = CLOSED;
        }
        result.push_back(sum);
        sum = 0;
    }
    return result;
}
