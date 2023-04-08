#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stack>
#include <queue>

#define FRESH 0
#define OPEN 1
#define CLOSED 2

using namespace std;
/**
 * Implementace neorientovaneho grafu pomoci seznamu sousednich vrcholu
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
        int state; ///< Mozne stavy vrcholu behem pruchodu - FRESH OPEN CLOSED
        int distance; ///< Vzdalenost od pocatecniho vrcholu pro pruchodu do sirky
    };

    vector <Node*> nodes; ///< Seznam vrcholu tvoricich graf

    /**
     * Inicializace potrebna pred spustenim libovolneho prouchodu.
     * Nastavi stav vsech vrcholu na FRESH a nastavi vzdalenosti na -1
     */
    void Init();

    /**
     * Rekurzivni volani pro rekurzivni pruchod do hlobuky.
     *
     * @param actualNode Aktualni vrchol
     */
    void DepthFirstRecursiveCall(Node* actualNode);

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
     * Spusti rekurzivni pruchod do hlobuky.
     *
     * @param startNumber Cislo pocatecniho vrcholu
     */
    void DepthFirstRecursive(int startNumber);

    /**
     * Spusti iterativni pruchod do hlobuky.
     *
     * @param startNumber Cislo pocatecniho vrcholu
     */
    void DepthFirstIterative(int startNumber);

    /**
     * Spusti pruchod do sirky.
     * Po skonceni pruchodu bude v kazdem vrcholu ulozena jeho nejvratsi vzdalenost od pocatecniho vrcholu
     *
     * @param startNumber Cislo pocatecniho vrcholu
     */
    void BreadthFirst(int startNumber);

    /**
     * Vrati vektor cisel vrcholu, ktere maji od pocatecniho vrcholu danou vzdalenost.
     *
     * @param startNumber Cislo pocatecniho vrcholu
     * @param distance pozadovana vzdalenost
     * @return Vektor cisel vrcholu, ktere mají od pocatecniho vrcholu vzdalenost rovnu hodnotě distance
     */
    vector<int> GetNodesWithGivenDistance(int startNumber, int distance);

    /**
     * Vrati soucty cisel v jednotlivych komponentach grafu
     *
     * @return Vektor cisel (pro každou komponentu jedno) reprezentující soucet cisel vrcholu v komponente
     */
    vector<int> ComponentSums();
};
