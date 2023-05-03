#include "GraphInMatrix.h"

vector<vector <int>> Permutations(vector <int> input)
{
    if (input.size() == 0) //trivialni reseni permutace nula prvku, vysledkem je prazdny vektor
        return vector<vector <int>> {vector<int>()};

    int currentCity = input.back(); //zmenseni velikosti vstupu o jedna, tj. „decrease and conquer“
    input.pop_back();

    vector<vector <int>> res = Permutations(input); // rekurzivni volani, vygenerujeme permutace n-1 prvku
    vector<vector <int>> output;

    for (vector <int>perm : res) //permutace n-1 prvku prepracujeme a dostaneme permutace n prvku
    {
        for (int i = 0; i <= perm.size(); i++)
        {
            vector <int>toAdd = perm;
            auto it = toAdd.begin();
            toAdd.insert(it + i, currentCity); //na i-tou pozici vlozime prvek
            output.push_back(toAdd);
        }
    }
    return output;
}

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
    int _vertexCount;
    file >> _vertexCount;

    Inicialize(_vertexCount);

    int from, to, weight;
    while (!file.eof())
    {
        file >> from >> to >> weight;
        AddEdge(from, to, weight);
    }
    file.close();
}

GraphInMatrix::~GraphInMatrix()
{
    for (int i = 0; i < vertexCount; i++)
        delete[] adjacencyMatrix[i];
    delete[] adjacencyMatrix;
}

void GraphInMatrix::AddEdge(int from, int to, int weight)
{
    if (from == to)
        return;
    adjacencyMatrix[from][to] = weight;
    adjacencyMatrix[to][from] = weight;
}

int GraphInMatrix::VertexDegree(int vertex)
{
    int degree = 0;
    for (int i = 0; i < vertexCount; i++)
        if (adjacencyMatrix[vertex][i])
            degree++;
    return degree;
}

void GraphInMatrix::ReportEdges()
{
    cout << "Graf na " << vertexCount << " vrcholech" << endl;
    cout << "Hrany: " << endl;
    for (int i = 0; i < vertexCount; i++)
        for (int j = i + 1; j < vertexCount; j++) //j zacina na i+1 - prochazime jen cast matice nad diagonalou, tedy vypisujeme hrany jen jednou
            if (adjacencyMatrix[i][j])
                cout << "hrana mezi vrcholy: " << i << " a " << j << " s vahou: "<< adjacencyMatrix[i][j]<< endl;
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
    for (int i = 0; i < vertexCount; i++)
    {
        int degree = 0;
        cout << "Vrchol s cislem " << i << " ma soudedy: ";
        for (int j = 0; j < vertexCount; j++)
            if (adjacencyMatrix[i][j])
                cout << j << " ";
        cout << endl;
    }
}

void GraphInMatrix::ReportDegrees()
{
    for (int i = 0; i < vertexCount; i++)
        cout << "Vrchol s cislem " << i << " ma stupen " << VertexDegree(i) << endl;
}

bool GraphInMatrix::IsComplete()
{
    for (int i = 0; i < vertexCount; i++)
        for (int j = i + 1; j < vertexCount; j++) //j zacina na i+1 - prochazime jen cast matice nad diagonalou
            if (!adjacencyMatrix[i][j])
                return false;
    return true;
}

void GraphInMatrix::GenerateAllPaths(int startVertex)
{
    vector <int> input;
    for (int i = 0; i < vertexCount; i++)//input pro funkci permutations
        input.push_back(i);

    vector<vector<int>> test = Permutations(input);

    for (int i = 0; i < test.size(); ++i) {
        if (test[i][0] == startVertex){
            test[i].push_back(startVertex);
            possiblePaths.push_back(test[i]);
        }
    }
}

void GraphInMatrix::PrintShortestPath(int startVertex)
{
    GenerateAllPaths(startVertex);
    int min = INT32_MAX;
    vector<int> shortestPath;
    int counter = 0;
    for (int i = 0; i < possiblePaths.size(); i++) {
        counter = 0;
        for (int j = 1; j < possiblePaths[i].size(); j++) {
            counter += adjacencyMatrix[startVertex][possiblePaths[i][j]];
            startVertex = possiblePaths[i][j];
        }
        if (counter < min){
            shortestPath.clear();
            min = counter;
            for (int j = 0; j < possiblePaths[i].size(); ++j) {
                shortestPath.push_back(possiblePaths[i][j]);
            }
        }
    }

    cout << "Nejkratsi cesta je: ";
    for (int num : shortestPath)
        cout << num << " ";
    cout << endl;
    cout << "Delka: " << min << endl;
}
