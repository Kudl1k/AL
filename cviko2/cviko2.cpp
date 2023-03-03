#include <iostream>
#include "arrayStack.h"

using namespace std;

//funkce, která zjistí, zdali je retezec palindrom, tj. čte se stejně zepredu jako zezadu
//priklady palindromu: oko, krk, nejen, kajak
//palindrom muze mit i sudy pocet znaku
//v implementaci využijte zásobník
bool palindrom(string retezec)
{
	arrayStack z;
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
	arrayStack z;

	return z.isEmpty();
}

int main()
{
	arrayStack z;
	int x;

	x = rand() % 10 + 1;
	cout << "Vkladam do zasobniku hodnotu " << x << endl;
	z.push(x);

	x = rand() % 10 + 1;
	cout << "Vkladam do zasobniku hodnotu " << x << endl;
	z.push(x);

	x = rand() % 10 + 1;
	cout << "Vkladam do zasobniku hodnotu " << x << endl;
	z.push(x);

	x = rand() % 10 + 1;
	cout << "Vkladam do zasobniku hodnotu " << x << endl;
	z.push(x);

	z.pop(x);
	cout << "Vybiram ze zasobniku odhnotu " << x << endl;

	z.pop(x);
	cout << "Vybiram ze zasobniku odhnotu " << x << endl;

	cout << "Vkladam do zasobniku hodnotu " << x << endl;
	z.push(x); x = rand() % 10 + 1;
	cout << "Vkladam do zasobniku hodnotu " << x << endl;
	z.push(x);

	z.pop(x);
	cout << "Vybiram ze zasobniku hodnotu " << x << endl;

	z.report();

	cout << "Test funkce palindrom:" << endl;
	cout << "oko: " << palindrom("oko") << endl;//Ok
	cout << "karel: " << palindrom("karel") << endl;//Not OK
	cout << "kajak: " << palindrom("kajak") << endl;//Ok
	cout << "kobylamamalybok: " << palindrom("kobylamamalybok") << endl;//Ok
	cout << "llokkoll: " << palindrom("llokkoll") << endl;//Ok

	cout << "Testovani parity zavorek" << endl;
	cout << testParity("{ [ ( a + b) * ( c – d ) + e ] / f }") << endl;//OK
	cout << testParity("( a + b * c – d + e / f") << endl;//Not ok - chybí pravá
	cout << testParity("{ ( [ a + b * e ) / f }") << endl;//Not ok - chybí pravá
	cout << testParity("[ ( a + b) + e ] / f }") << endl;//Not ok - chybí levá
	cout << testParity("{[ ( a + b) + e ] / f }") << endl;//OK
	cout << testParity("{ c + [ ( a + b) + e ] / f }}") << endl;//Not ok - chybí levá
}