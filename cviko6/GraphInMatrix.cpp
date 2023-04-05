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
    fstream file(path);
    file >> vertexCount;
    while (true){
        int a = 0, b = 0;
        if (file.eof()) break;
        file >> a >> b;
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
    return -1;
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

}

void GraphInMatrix::ReportDegrees()
{

}

bool GraphInMatrix::IsComplete()
{
    return false;
}

bool GraphInMatrix::IsStar()
{
    return false;
}

