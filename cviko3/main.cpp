#include <queue>
#include "linkedQueue.h"
#include <iostream>

using namespace std;

void simulaceEshop(int zakazniku_celkem, int krok) //misto n a m radeji pouzijeme vice vypovidajici nazvy promennych: zakazniku_celkem a krok
{
	linkedQueue* f = new linkedQueue[3];
	int cislo_prichoziho = 1;
	int jednotek = 1;
	int cislo_obslouzeneho;
	bool flag = true;

	while (1)
	{
		for (int i = 0; i < zakazniku_celkem % krok && cislo_prichoziho <= zakazniku_celkem; i++)
		{
			if (f[0].getCount() <= f[1].getCount() && f[0].getCount() <= f[2].getCount())
			{
				f[0].enqueue(cislo_prichoziho);
				cout << "Cislo prichoziho do 1.fronty: " << cislo_prichoziho << endl;
			}
			else if (f[1].getCount() <= f[0].getCount() && f[1].getCount() <= f[2].getCount()){
				f[1].enqueue(cislo_prichoziho);
				cout << "Cislo prichoziho do 2.fronty: " << cislo_prichoziho << endl;
			}
			else if (f[2].getCount() <= f[0].getCount() && f[2].getCount() <= f[0].getCount()){
				f[2].enqueue(cislo_prichoziho);
				cout << "Cislo prichoziho do 3.fronty: " << cislo_prichoziho << endl;

			}
			cislo_prichoziho++;
		}
		
		

		for (int i = 0; i < 2 || !f[0].isEmpty(); i++)
		{
			f[0].dequeue(cislo_obslouzeneho);
			//cout << "prvni hotovo: " << cislo_obslouzeneho << endl;
		}
		for (int i = 0; i < 2 || !f[1].isEmpty(); i++)
		{
			f[1].dequeue(cislo_obslouzeneho);
			//cout << "druhe hotovo: " << cislo_obslouzeneho << endl;
		}
			
		if (f[2].dequeue(cislo_obslouzeneho)){
			//cout << "treti hotovo: " << cislo_obslouzeneho << endl;
		} 

		if (f[0].isEmpty() && f[1].isEmpty() && f[2].isEmpty() && cislo_prichoziho >= zakazniku_celkem)
		{
			break;
		}	
		jednotek++;
	}

	cout << "Obslouzeni trvalo " << jednotek << " jednotek casu." << endl;

	delete[] f;
}

void horkyBrambor(vector<string> vstup,int k)
{
	const int poradi_pro_vypadnuti = 7;
	int kolo = 1;
	queue<string> jmena;
	string aktualni;

	for (int i = 0; i < vstup.size(); i++)
		jmena.push(vstup[i]);

	while (jmena.size() > 1)
	{
		aktualni = jmena.front();
		cout << kolo << " brombor má: " << aktualni << endl;
		jmena.pop();
		if (kolo % poradi_pro_vypadnuti == 0){
			cout << aktualni << " vypadnul" << endl;
		}
		else{
			jmena.push(aktualni);
		}
		kolo++;
	}
	cout << "Vítěz: " << jmena.front() << endl;

}


int main()
{
	// linkedQueue* f = new linkedQueue(); // dynamicke vytvoreni objektu pres ukazatel
	// int x;

	// //vlozime 4 prvky
	// cout << "Vlozeni 4 prvku: " << endl;
	// for (int i = 0; i < 4; i++)
	// {
	// 	x = rand() % 10;
	// 	f->enqueue(x);
	// 	cout << "Vlozeno: " << x << endl;
	// }
	// f->report();

	// // vybereme prvek, vytiskneme
	// cout << "Vyber 1 prvku" << endl;
	// if (f->dequeue(x))
	// 	cout << "Vybrano: " << x << endl;
	// else
	// 	cout << "Fronta je prazdna" << endl;


	// //zkusime vybrat více prvků než je ve frontě
	// cout << "Vyber 10 prvku" << endl;
	// for (int i = 0; i < 10; i++)
	// {
 	// 	if (f->dequeue(x))
	// 		cout << "Vybrano: " << x << endl;
	// 	else
	// 		cout << "Fronta je prazdna" << endl;
	// }

	// //znova něco vložíme
	// cout << "Vlozeni 4 prvku: " << endl;
	// for (int i = 0; i < 4; i++)
	// {
	// 	x = rand() % 10;
	// 	f->enqueue(x);
	// 	cout << "Vlozeno: " << x << endl;
	// }

	// //vyber
	// cout << "Vyber 2 prvku" << endl;
	// for (int i = 0; i < 2; i++)
	// {
	// 	if (f->dequeue(x))
	// 		cout << "Vybrano: " << x << endl;
	// 	else
	// 		cout << "Fronta je prazdna" << endl;
	// }

	// f->report();


	// delete f;//smazani, volani destruktoru

	//simulace vydejny
	simulaceEshop(25, 3);//obslouzeni by melo trvat 24 jednotek casu

	// // //horky brambor
	// vector<string> jmena;

	// jmena.push_back("Franta");
	// jmena.push_back("Lenka");
	// jmena.push_back("Michal");
	// jmena.push_back("Martin");
	// jmena.push_back("Drahomira");

	// horkyBrambor(jmena, 7);//vitezem by mel byt martin
	
}