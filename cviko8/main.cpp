#include <iostream>
#include <vector>
#include "BST.h"

using namespace std;

int main()
{
    BST strom;
    strom.Insert(6);
    strom.Insert(4);
    strom.Insert(5);
    strom.Insert(3);
    strom.Insert(9);
    strom.Insert(7);

    strom.InOrder();

    cout << strom.Search(0) << endl;
    cout << strom.Search(1) << endl;
    cout << strom.Search(4) << endl;
    cout << strom.Search(9) << endl;

    cout << endl;

    cout << strom.MinKey() << endl;
    cout << strom.MaxKey() << endl;
}