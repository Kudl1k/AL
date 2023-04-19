#include <iostream>
#include <vector>

#include <cstdlib>
#include <ctime>

#include "BST.h"

using namespace std;

vector<int> generateRandomVector();




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

    vector<int> result = strom.ToVector();

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    cout << strom.MinKey() << endl;
    cout << strom.MaxKey() << endl;

    vector<int> randomVector = generateRandomVector();
    BST strom2;
    for (int i = 0; i < randomVector.size(); ++i) {
        strom2.Insert(randomVector[i]);
    }

    vector<int> result2 = strom2.ToVector();

    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i] << " ";
    }
    cout << endl;
}

vector<int> generateRandomVector(){
    vector<int> result(10000);

    srand(std::time(nullptr));

    for (int i = 0; i < result.size(); ++i) {
        result[i] = rand() % 100 + 1;
    }
    return result;
}


