#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Funkce pro generovani permutaci
 *
 * @param input Vektor n cisel jejichz permutace chceme vygenerovat
 * @return Vektor jehoz prvky jsou jednotlive permutace, tj. vektory cisel
 */
vector<vector <int>> Permutations(vector <int> input);

/**
 * Implementace neorientovaneho vazeneho grafu pomoci matice sousednosti
 */
class GraphInMatrix
{

private:

    int** adjacencyMatrix; ///< Matice sousedosti
    int vertexCount; ///< Pocet vrcholu

    vector<vector <int>> possiblePaths; ///< Mozne cesty ke spocteni delky

    /**
     * Inicializuje matici sousednosti.
     *
     * @param _vertexCount Pocet vrcholu
     */
    void Inicialize(int _vertexCount);

    /**
     * Vygeneruje cesty pres vsechny vrcholy v kompletnim grafu.
     * Vygenerovane cesty budou zacinat a koncit ve vrhcolu jehoz cislo predame jako parametr.
     * Vygenerovane cesty funkce ulozi do promenne  possiblePaths
     *
     * @param startVertex Cislo pocatecniho (a koncoveho) vrcholu
     */
    void GenerateAllPaths (int startVertex);

public:

    /**
     * Vytvori graf bez hran s danym poctem vrcholu.
     *
     * @param _vertexCount Pocet vrcholu
     */
    GraphInMatrix(int _vertexCount);

    /**
     * Vytvori graf ze specifikace v textovem souboru.
     *
     * @param path Cesta k souboru
     */
    GraphInMatrix(string path);

    /**
     * Destruktor, ktery zajisti dealokaci matice sousednosti.
     */
    ~GraphInMatrix();

    /**
     * Prida neorientovanou vazenou hranu do grafu.
     *
     * @param from Prvni vrchol
     * @param to Druhy vrchol
     * @param weight Vaha hrany
     */
    void AddEdge(int from, int to, int weight);

    /**
     * Vrati stupen vrcholu predaneho jako parametr.
     *
     * @param vertex Cislo vrcholu jehoz stupen chceme zjistit
     * @return Stupen prislusneho vrcholu
     */
    int VertexDegree(int vertex);

    /**
     * Vypise pocet vcholu a jednotlive hrany grafu.
     */
    void ReportEdges();

    /**
     * Vypise matici sousednosti.
     */
    void ReportMatrix();

    /**
     * Pro kazdy vrchol vypise jeho sousedy.
     */
    void ReportNeighbours();

    /**
     * Pro kazdy vrchol vypocita a vypise jeho stupen.
     */
    void ReportDegrees();

    /**
     * Urci zdali je graf kompletni.
     *
     * @return Vraci true pokud je graf kompletni, v opacnem pripade vraci false.
     */
    bool IsComplete();

    /**
     * Funkce resici problem obchodniho cestujiciho.
     * Vytiskne nejkratsi cestu prochazejici vsemi vrcholy ohodnoceneho kompletniho grafu vcetne jeji delky.
     *
     * @param startVertex Cislo pocatecniho (a koncoveho) vrcholu
     */
    void PrintShortestPath(int startVertex);
};
