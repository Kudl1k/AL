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
    for (int i = 0; i < v.size() - 2; i++)
    {
        
    }
    
}

//vyhledá jméno osoby s příslušným ID
string binary_search(vector<person> v, int id)
{
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
    /*for (int i = 0; i < osoby.size(); i++)
        cout << osoby[i].id << " " << osoby[i].jmeno << endl;*/

    int klic;

    //doplňte načteni kličů ze souboru a vyhledání příslušného jména pro každý z nich


    soubor.close(); //soubor zavřeme
}
