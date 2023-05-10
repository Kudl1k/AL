#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct item
{
    int ID;
    int weight;
    int price;
};

vector<vector <item>> subsets(vector <item> input)
{
    if (input.size() == 0)
        return vector<vector <item>> {vector<item>()};//permutace prazdne mnoziny je prazdna mnozina

    item currentName = input.back(); //zmenseni problemu o jedna, tj. „decrease and conquer“
    input.pop_back();

    vector<vector<item>> res = subsets(input); // reseni instance o jedna mensi
    vector<vector<item>> output;

    for (vector<item> perm : res)
    {
        output.push_back(perm);
        perm.push_back(currentName);
        output.push_back(perm);
    }
    return output;

}

int main(int argc, char **argv)
{
    ifstream soubor(argv[1]);

    if (!soubor.is_open()){
        cout << "Soubor nelze otevřít!" << endl;
        return 1;
    }

    int capacity;

    cout << "Reseni problemu batohu." << endl;
    cout << "------------------------------------------" << endl;
    soubor >> capacity;

    cout << "Kapacita batohu je: " << capacity << endl;

    vector<item> items;
    item newItem;

    while(!soubor.eof())
    {
        soubor >> newItem.ID;
        soubor >> newItem.weight;
        soubor >> newItem.price;
        items.push_back(newItem);
        cout << "Predmet " << newItem.ID << " hmotnost: " <<newItem.weight<<" cena: "<<newItem.price<< endl;
    }

    soubor.close();

    int maximumPrice = INT32_MIN;
    vector<item> max;

    //vygenerujte vsechny podmnoziny
    //pro kazdou podmnozinu sectete hmnotnosti a ceny
    //najdete podmnozinu s maximalnim souctem cen, pricemz soucet hmotnosti musi byt mensi nebo roven kapacite batohu

    vector<vector<item>> podmnoziny = subsets(items);

    for (int i = 0; i < podmnoziny.size(); ++i) {
        int value = 0;
        int weight = 0;
        for (int j = 0; j < podmnoziny[i].size(); ++j) {
            value += podmnoziny[i][j].price;
            weight += podmnoziny[i][j].weight;
        }
        if (weight <= capacity && value > maximumPrice){
            maximumPrice = value;
            max = podmnoziny[i];
        }
    }


    cout << "------------------------------------------" << endl;
    cout << "Optimalni reseni: ";
    for (item it : max)
        cout << it.ID << " ";
    cout << endl;
    cout << "Jejich hmotnost: ";
    for (item it : max) {
        cout << it.weight << " ";
    } cout << endl;
    cout << "Celkova cena: " << maximumPrice << endl;



}
