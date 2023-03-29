#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct person
{
    int ID;
    string jmeno;
};

//setřídí záznamy ve vektrou podle id
void selection_sort(vector<person>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int min = i;
        for (int j = i+1; j < v.size(); j++)
        {
            if (v[j].ID < v[min].ID)
            {
                min = j;
            }   
        }
        if (min != i)
        {
            swap(v[i],v[min]);
        }
    }
}

//vyhledá jméno osoby s příslušným ID
string binary_search(vector<person> v, int id)
{
    int l = 0;
    int r = v.size()-1;
    int m = 0;
    while (l <= r)
    {
        m = (l + r)/2;
        if (id == v[m].ID)
        {
            return v[m].jmeno;
        }
        else if (id < v[m].ID){
            r = m-1;
        } else {
            l = m +1;
        }
    }
    return "nenalezeno";
}

int main()
{
    int pocetZaznamu;
    int pocetDotazu;
    
    ifstream soubor("data.txt"); //vytvoreni „streamu“ pro cteni ze souboru 

    soubor >> pocetZaznamu >> pocetDotazu; //pouziti operatoru '>>' stejným způsobem, jako bychom četli ze standardního vstupu (cin)

    vector<person> osoby(pocetZaznamu);  //vytvoreni vektoru dane velikosti

    for (int i = 0; i < pocetZaznamu; i++)
    {
        soubor >> osoby[i].ID;
        soubor >> osoby[i].jmeno;
    }
    
    selection_sort(osoby); //seřazení

    //výpis pro kontrolu seřazení
    for (int i = 0; i < osoby.size(); i++)
        cout << osoby[i].ID << " " << osoby[i].jmeno << endl;

    int klic[pocetDotazu];

    //doplňte načteni kličů ze souboru a vyhledání příslušného jména pro každý z nich

    for (int i = 0; i < pocetDotazu; i++)
    {
        soubor >> klic[i];
    }

    for (int i = 0; i < pocetDotazu; i++)
    {
        cout << i+1 <<". hledané jméno je: " << binary_search(osoby,klic[i]) << endl;
    }
    
    soubor.close(); //soubor zavřeme
}
