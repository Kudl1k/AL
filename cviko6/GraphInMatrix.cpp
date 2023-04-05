#include "GraphInMatrix.h"

void GraphInMatrix::Inicialize(int _vertexCount)
{
    vertexCount = _vertexCount;
    adjacencyMatrix = new int* [vertexCount];
    for (int i = 0; i < vertexCount; i++)
    {
        adjacencyMatrix[i] = new int[vertexCount];
        for (int j = 0; j < vertexCount; j++)
            adjacencyMatrix[i][j] = 0;
    }
}

GraphInMatrix::GraphInMatrix(int _vertexCount)
{
    Inicialize(_vertexCount);
}

GraphInMatrix::GraphInMatrix(string path)
{
    ifstream file(path);
    if (!file.is_open()){
        cout << "Soubor nejde otevrit";
        exit(1);
    }
    file >> vertexCount;
    Inicialize(vertexCount);
    while (true){
        int a = 0, b = 0;
        if (file.eof()) break;
        file >> a;
        file >> b;
        AddEdge(a,b);
    }
    file.close();
}

GraphInMatrix::~GraphInMatrix()
{
    for (int i = 0; i < vertexCount; i++)
        delete[] adjacencyMatrix[i];
    delete[] adjacencyMatrix;
}

void GraphInMatrix::AddEdge(int from, int to)
{
    if (from == to)
        return;
    adjacencyMatrix[from][to] = 1;
    adjacencyMatrix[to][from] = 1;
}

int GraphInMatrix::VertexDegree(int vertex)
{
    int counter = 0;
    for (int i = 0; i < vertexCount; ++i) {
        if (adjacencyMatrix[vertex][i] == 1){
            counter++;
        }
    }
    return counter;
}

void GraphInMatrix::ReportEdges()
{
    cout << "Graf na " << vertexCount << " vrcholech" << endl;
    cout << "Hrany: " << endl;
    for (int i = 0; i < vertexCount ; i++)
        for (int j = i + 1; j < vertexCount ; j++) //j zacina na i+1 - prochazime jen cast matice nad diagonalou, tedy vypisujeme hrany jen jednou
            if (adjacencyMatrix[i][j])
                cout << "hrana mezi vrcholy: " << i << " a " << j << endl;
}

void GraphInMatrix::ReportMatrix()
{
    cout << "Matice sousednosti:" << endl;
    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < vertexCount; j++)
            cout << adjacencyMatrix[i][j] << " ";
        cout << endl;
    }
}

void GraphInMatrix::ReportNeighbours()
{
    cout << "Sousedi:" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        cout << "vrchol " << i << " ma tyto sousedy: ";
        for (int j = 0; j < vertexCount; ++j) {
            if (adjacencyMatrix[i][j] == 1){
                cout << j << ", ";
            }
        }
        cout << endl;
    }
}

void GraphInMatrix::ReportDegrees()
{
    cout << "Stupne:" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        int counter = 0;
        cout << "vrchol " << i << " ma takovy stupen: ";
        for (int j = 0; j < vertexCount; ++j) {
            if (adjacencyMatrix[i][j] == 1){
                counter++;
            }
        }
        cout << counter << endl;
    }
}

bool GraphInMatrix::IsComplete()
{
    int numEdges = 0;
    for (int i = 0; i < vertexCount; i++) {
        for (int j = i + 1; j < vertexCount; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                numEdges++;
            }
        }
    }
    if (numEdges == vertexCount*(vertexCount-1)/2) {
        return true;
    }

    return false;
}

bool GraphInMatrix::IsStar()
{
    int numEdges = 0;
    for (int i = 0; i < vertexCount; i++) {
        for (int j = i + 1; j < vertexCount; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                numEdges++;
            }
        }
    }
    if (numEdges == vertexCount-1) {
        int center = -1;
        bool isStar = true;

        for (int i = 0; i < vertexCount; i++) {
            int degree = 0;

            for (int j = 0; j < vertexCount; j++) {
                if (i != j && adjacencyMatrix[i][j] == 1) {
                    degree++;
                }
            }

            if (degree == vertexCount-1) {
                if (center != -1) {
                    isStar = false;
                    break;
                }
                center = i;
            } else if (degree != 1) {
                isStar = false;
                break;
            }
        }

        if (isStar && center != -1) {
            return true;
        }
    }

    return false;
}

