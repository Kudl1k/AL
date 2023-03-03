#include <iostream>
#include <string>
#include <vector>

using namespace std;

//cviceni 1. -- retezce a vektory v C++

//------------1.řetězce----------------

//průchod řetězcem a tisk jednotlivých znaků s využitím indexů (stejný princip jako práce s polem)
//funkce length vraci delku retezce (počet znaků)
void print_characters_indexes(string s)
{
    for (int i = 0; i < s.length(); i++)
        cout << s[i] << " ";
    cout << endl;
}

//průchod řetězcem a tisk jednotlivých znaků s využitím iterátoru
//iterátor je ukazatel na prvek pole, je možno použít operátor dereference a ukazatelovou aritmetiku
void print_characters_iterator(string s)
{
    for (string::iterator it = s.begin(); it != s.end(); it++) //přičtením jedničky posuneme iterátor na další znak řetězce
        cout << *it << " ";//dereference, tj. přístup k hodnotě
    cout << endl;
}

//funkce, která pro zadaný řetězec vrátí řetězec, ve kterém je každé písmeno duplikováno.
//průchod řetězcem pomocí konstrukce foreach
string duplication(string input)
{
    string result = "";
    for (char c : input)
        result = result + c + c; //přičíst lze i jeden znak, tj. objekt typu char
    return result;
}

//implementujte funkci, která zjistí, zdali je retezec palindrom, tj. čte se stejně zepredu jako zezadu
//viz https://cs.wikipedia.org/wiki/Palindrom
//priklady palindromu: oko, krk, nejen, kajak, kobylamamalybok
//palindrom muze mit i sudy pocet znaku
//implementujte rekurzivne
//muze se hodit funkce erase, viz https://cplusplus.com/reference/string/string/erase/
bool palindrom(string retezec)
{
    int j = retezec.length()-1;
    for (int i = 0; i < retezec.length(); i++,j--)
    {
        if (retezec[i] != retezec[j]) return false;
    }
    return true;
}

//------------2.vektory----------------

//průchod vektorem a tisk hodnot s využitím indexů (stejný princip jako práce s polem)
//funkce size vraci pocet prvku uložených ve vektoru
void print_vector_indexes(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

//průchod vektorem a tisk hodnot s využitím iterátoru
//iterátor je ukazatel na prvek pole, je možno použít operátor dereference a ukazatelovou aritmetiku
//iterátor je důležitý pro užitecné funkce erase a insert
//erase a insert u vektrou nepřijímají jako parametr index pozice, nýbrž iterátor narozdíl od stejných funkcí u řetězců
void print_vector_iterator(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) //přičtením jedničky posuneme iterátor na další prvek vektoru
        cout << *it << " ";//dereference, tj. přístup k hodnotě
    cout << endl;
}

//nalnění vektoru čísly v příslušném rozsahu
//proč je zde ampersand ?
//proč u jinych funkci, kde je parametrem vektor ampersand není potřeba?
void fill_vector(vector<int>& v, int start, int end)
{
    v.clear();
    for (int i = start; i <= end; i++)
        v.push_back(i);
}

struct person
{
    int ID;
    string name;
};

//sekvenčním vyhledáváním vyhledá a vrátí jméno osoby se zadaným ID
//v případě nenalezení vrátí řetězec "nenalezeno"
//průchod vektorem pomocí konstrukce foreach
string find_name(vector<person> input, int ID)
{
    for (person per : input)
    {
        if (per.ID == ID)
            return per.name;
    }
    return "nenalezeno";
}

//implementujte funkci, která pro dané číslo n vrátí vektor prvočísel menších než n
//využijte algoritmus „eratosthenovo síto“, viz prezentace z přednášek
void erastothenes(int n)
{
    vector<int> primes(n+1, true);
    vector<int> result;

    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            result.push_back(i);
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
}

int main()
{
    // string s1, s2;
    // cout << "Zadej retezec s1." << endl;
    // cin >> s1;                              // načtení řetězce z klávesnice
    // cout << "Zadej retezec s2." << endl;
    // cin >> s2;
    // cout << "Spojeni retezcu s1 + s2:  " << s1 + s2 << endl;
    // cout << "Spojeni retezcu s1 + s2 po znacich:  ";
    // print_characters_indexes(s1 + s2);
    // cout << "Zdvojeni znaku v retezci s1: " << duplication(s1) << endl;
    

    // //vektor celych čísel, naplnění předem daným počtem prvků při inicializaci
    // vector<int> vektor{ 1,2,3,4,5 };
    // cout << "Prvky vektoru: ";
    // print_vector_indexes(vektor);
    // vektor.clear(); //vyprazdneni vektoru
    // fill_vector(vektor, 1, 10); //naplneni cisly od 1 do 10
    // cout << "Prvky vektoru: ";
    // print_vector_iterator(vektor);

    // //vektor struktur person, naplnění předem daným počtem prvků při inicializaci
    // vector<person> vektor2{ {1,"Michal"},{2,"Martin"},{3,"Ondrej"},{4,"Tomas"} };
    // //vyhledani osoby s ID 3
    // cout << "Osoba s ID 3 je: " << find_name(vektor2, 3) << endl;
    // cout << "Osoba s neexistujicim ID 6 je: " << find_name(vektor2, 6) << endl;


    //testy vašich funkci palindrom a erastothenes

    string s3;
    cout << "Zadejte retezec s3: ";
    cin >> s3;
    cout << palindrom(s3) << endl;

    int n;
    cout << "Zadejte číslo: ";
    cin >> n;
    erastothenes(n);

    return 0;
}
