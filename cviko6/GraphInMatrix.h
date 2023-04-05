#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * Implementace neorientovaneho grafu pomoci matice sousednosti
 */
class GraphInMatrix
{

private:

    int** adjacencyMatrix; ///< Matice sousedosti
    int vertexCount; ///< Pocet vrcholu

    /**
     * Inicializuje matici sousednosti.
     *
     * @param _vertexCount Pocet vrcholu
     */
    void Inicialize(int _vertexCount);

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
     * Prida neorientovanou hranu do grafu.
     *
     * @param from Prvni vrchol
     * @param to Druhy vrchol
     */
    void AddEdge(int from, int to);

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
     * Urci, zdali ma graf strukturu hvezdy.
     *
     * @return Vraci true pokud ma graf strukturu hvezdy, v opacnem pripade vraci false.
     */
    bool IsStar();
};
