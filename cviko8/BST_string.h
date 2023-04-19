#pragma once
#include <iostream>
#include <vector>

using namespace std;


class BST_string {
private:
    struct node
    {
        string key; ///< Klic v uzlu stromu
        int count = 0; ///< Pocet výskytů
        node* left; ///< Odkaz na leveho potomka
        node* right; ///< Odkaz na praveho potomka
    };

    node* root;

    /**
     * Rekurzivni volani funkce pro vlozeni klice do stromu
     *
     * @param value Vkladany klic
     * @param nod Aktualni vrchol
     */
    void Insert(string value, node*& nod);

    /**
     * Rekurzivni volani InOrder prchuchodu stromem
     *
     * @param nod Aktualni vrchol
     */
    void InOrder(node* nod);

    /**
     * Rekurzivne smaze vsechny uzly stromu pocinaje uzlem predanym jako parametr
     * Vyuziti v destruktoru
     *
     * @param nod Aktualni vrchol
     */
    void Clear(node* nod);


    bool Search(string value, node* nod);

public:

    /**
    * Konstruktor, ktery vytvori prazdny strom bez uzlu
    */
    BST_string();

    /**
     * Destruktor, ktery smaze vsechny uzly
     * Vola funkci Clear
     */
    ~BST_string();

    /**
     * Funkce pro vlozeni klice do stromu
     * Pokud se ve stromu dany klic jiz nachazi, nestane se nic
     *
     * @param value Vkladany klic
     */
    void Insert(int value);

    bool Search(string value);


};