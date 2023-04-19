#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;
/**
 * Implementace orientovaneho grafu pomoci seznamu sousednich vrcholu
 */
class Graph
{

private:
    /**
     * Struktura reprezentujici vrchol grafu
     */
    struct Node
    {
        vector<Node*> neighbours; ///< Seznam sousedicich vrcholu
        int value; ///< Hodnota vrcholu - nezaporne cele cislo

        int indegree;   ///< "vstupni stupen" grafu, reprezentuje pocet prichozich hran
        bool visited;   ///< booleovska promenna, detekuje, ze by jiz vrchol zpracovan a pridan do vysledku topo. trideni
    };

    vector <Node*> nodes; ///< Seznam vrcholu tvoricich graf

    /**
     * Inicializace potrebna pred spustenim topologickeho trizeni
     * Nastavi indegree na prislusnou hodnotou a hodnoty visited na false
     */
    void Init();

public:
    /**
     * Vytvori graf ze specifikace v textovem souboru.
     *
     * @param path Cesta k souboru
     */
    Graph(string path);

    /**
     * Destruktor, ktery zajisti dealokaci dynamicky alokovanych vrcholu.
     */
    ~Graph();

    /**
     * Algoritmus topologickeho trideni
     *
     * @return Vraci vektor cisel vrcholu v topologickem poradi
     */
    vector<int> SourceRemoval();
};