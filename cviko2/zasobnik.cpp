#include "zasobnikStack.h"

#include <iostream>
using namespace std;


//funkce, která zjistí, zdali je retezec palindrom, tj. čte se stejně zepredu jako zezadu
//priklady palindromu: oko, krk, nejen, kajak
//palindrom muze mit i sudy pocet znaku
//v implementaci využijte zásobník
bool palindrom(string retezec)
{
	arrayStack z(50);
    int flag = 0;
    int mySize = 0;
    if (retezec.size() % 2 == 0) mySize = retezec.size()/2;
    else mySize = retezec.size()/2 + 1;
    for (int i = 0; i < mySize; i++)
    {
        z.push(retezec[i]);
    }
    for ( int i = mySize; i < retezec.size(); i++)
    {
        int c;
        z.pop(c);
        if (retezec.size() % 2 != 0 && flag == 0) {
            flag = 1;
            i--;
            continue;
        }
        if (c != retezec[i])
        {
            return false;
        }
    }
	return true;
}

//funkce otestuje zdali je vstupni retezec spravne ozavorkovany vyraz
//algoritmus prochazi znak po znaku vstupni retezec
//pokud narazi na levou zavorku, ulozi ji na zasobnik
//pokud narazi na pravou zavorku, odebere prvek z vrcholu zasobniku a zkontroluje, zda je to leva zavorka stejneho druhu
//pokud narazi na pravou zavorku a zasobnik je prazdny - chyba
//ostatni znaky ignorujeme
//na konci musi byt zasobnik prazdny
bool testParity(string retezec)
{
	arrayStack z(50);

	return z.isEmpty();
}




int main(){
    cout << "Test funkce palindrom:" << endl;
	cout << "oko: " << palindrom("oko") << endl;//Ok
	cout << "karel: " << palindrom("karel") << endl;//Not OK
	cout << "kajak: " << palindrom("kajak") << endl;//Ok
	cout << "kobylamamalybok: " << palindrom("kobylamamalybok") << endl;//Ok
	cout << "llokkoll: " << palindrom("llokkoll") << endl;//Ok
    return 0;
}