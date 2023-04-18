#pragma once
#include <iostream>
#include <vector>

using namespace std;
/**
 * Implementace binarniho vyhledavaciho stromu
 */
class BST
{
private:

    /**
     * Struktura reprezentujici uzel stromu
     */
    struct node
    {
        int key; ///< Klic v uzlu stromu
        node* left; ///< Odkaz na leveho potomka
        node* right; ///< Odkaz na praveho potomka
    };

    node* root; ///< Koren stromu

    //privatni metody pro rekurzivni volani
    //obsahuji navic parametr pro rekurzi, ukazatel na aktualni uzel stromu

    /**
     * Rekurzivne smaze vsechny uzly stromu pocinaje uzlem predanym jako parametr
     * Vyuziti v destruktoru
     *
     * @param nod Aktualni vrchol
     */
    void Clear(node* nod);

    /**
     * Rekurzivni volani funkce pro vlozeni klice do stromu
     *
     * @param value Vkladany klic
     * @param nod Aktualni vrchol
     */
    void Insert(int value, node*& nod);

    /**
     * Rekurzivni volani InOrder prchuchodu stromem
     *
     * @param nod Aktualni vrchol
     */
    void InOrder(node* nod);

    /**
     * Rekurzivni volani funkce pro vyhledani klice ve stromu
     *
     * @param value Hledany klic
     * @param nod Aktualni vrchol
     * @return True nebo False v zavislosti na tom, zdali je hledani uspecne ci nikoliv
     */
    bool Search(int value, node* nod);

    /**
     * Rekurzivni volani funkce pro vyhledani nejmensiho klice ve stromu
     *
     * @param nod Aktualni vrchol
     * @return Hodnota nejmensiho klice
     */
    int MinKey(node* nod);

    /**
     * Rekurzivni volani funkce pro vyhledani nejvetsiho klice ve stromu
     *
     * @param nod Aktualni vrchol
     * @return Hodnota nejvetsiho klice
     */
    int MaxKey(node* nod);

    /**
     * Rekurzivni volani funkce pro extrakci klicu ze stromu do vektoru, serazeno vzestupne
     *
     * @param nod Aktualni vrchol
     * @return Vektor obsahujici hodnoty klicu ze stromu, serazeno vzestupne
     */
    vector<int> ToVector(node* nod);

public:

    /**
     * Konstruktor, ktery vytvori prazdny strom bez uzlu
     */
    BST();

    /**
     * Destruktor, ktery smaze vsechny uzly
     * Vola funkci Clear
     */
    ~BST();

    /**
     * Funkce pro vlozeni klice do stromu
     * Pokud se ve stromu dany klic jiz nachazi, nestane se nic
     *
     * @param value Vkladany klic
     */
    void Insert(int value);

    /**
     * InOrder prchuchod stromem
     * Klice zpracujumeme (tj. vytiskneme) v poradi od nejmensiho po nejvetsi
     */
    void InOrder();

    /**
     * Funkce pro vyhledani klice ve stromu
     *
     * @param value Hledany klic
     * @return True nebo False v zavislosti na tom, zdali je hledani uspecne ci nikoliv
     */
    bool Search(int value);

    /**
     * Funkce pro vyhledani nejmensiho klice ve stromu
     *
     * @return Hodnota nejmensiho klice
     */
    int MinKey();

    /**
     * Funkce pro vyhledani nejvetsiho klice ve stromu
     *
     * @return Hodnota nejvetsiho klice
     */
    int MaxKey();

    /**
     * Funkce pro extrakci klicu ze stromu do vektoru, serazeno vzestupne
     *
     * @return Vektor obsahujici hodnoty klicu ze stromu, serazeno vzestupne
     */
    vector<int> ToVector();
};
