#include "linkedQueue.h"
#include <iostream>

using namespace std;

linkedQueue::linkedQueue()
{
	head = nullptr;	//inicializace ukazatelu
	tail = nullptr;
	count = 0;
}

bool linkedQueue::isEmpty()
{
	return count == 0; 
}

int linkedQueue::getCount()
{
	return count;
}

void linkedQueue::enqueue(int x)
{
	item* p = new item;//alokace nove polozky
	p->value = x;
	p->next = nullptr;

	if (isEmpty()) 
		head = p;  //pokud je fronta prazdna nove pridany prvek se stane hlavou fronty
	else
		tail->next = p; //pokud fronta neni prazdna pripojime novy prvek za ocas 
	
	tail = p;  //nove pridany prvek se vzdy stava ocasem fronty

	count++;
}

bool linkedQueue::dequeue(int& x)
{
	if (isEmpty()) 
		return false; 
	item* p = head;  //do p ulozime aktualni hlavu fronty
	x = p->value;  //do vystupni promenne ulozime hodnotu
	head = p->next;  //nova hlava fronty 

	if (head == nullptr)    //pokud jsem vybral posledni prvek, nastavim ocas na nullptr
		tail = nullptr;
	
	delete p;       //mazani polozk
	count--;
	
	return true;	
}

bool linkedQueue::peek(int& x)
{
	if (isEmpty())
		return false;
	x = head->value;
	return true;
}

void linkedQueue::report()
{
	if (isEmpty())
		cout << "Fronta je prazdna." << endl;
	else
	{
		cout << "Fronta obsahuje " << count << " prvku." << endl; 
		cout<<"Obsah fronty (od zacatku) :" << endl;
		item* p = head;  //promenna pro aktualni prvek pri pruchodu fronty v cyklu
		while (p != nullptr) //dokud nedojdu na konec fronty
		{
			cout << p->value << " ";  //tisk
			p = p->next;			//prechod na dalsi prvek
		}
		cout << endl;
	}
}

void linkedQueue::clear()
{
	cout << "Mazu vsechny prvky fronty!" << endl;;  //uklid, dokud nebude fronta prazdna, odebirame prvky pomoci get
	int x;
	while (dequeue(x)) //dokud get vraci true 
		cout << "Odebrano a smazano: " << x << endl;
}

linkedQueue::~linkedQueue()
{
	cout << "Volame destruktor!" << endl;
	clear();
}
