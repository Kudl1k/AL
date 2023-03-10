#pragma once
class linkedQueue
{

private:
	struct item
	{
		int value;
		item* next;//ukazatel na dalsi prvek (od hlavy smerem k ocasu), ukazatel na toho co ve fronte stoji za mnou
	};

	int count; //pocet prvku ve fronte

	item* head;  //hlava, tj. zacatek fronty, prvni prvek na rade ktery bude odebran pri volani get
	item* tail;  //ocas fronty, posledni prvek ve fronte

public:
	linkedQueue();

	bool isEmpty();        //test prazdnosti fronty
	int getCount();

	void enqueue(int x);   //vlozeni cisla do fronty, nemuze selhat
	bool dequeue(int& x);  //vyber z fronty, podle uspechu nebo neuspechu vraci true, respektive false

	bool peek(int& x); //precteni prvniho prvku fronty bez jeho odebrani, podle uspechu nebo neuspechu vraci true, respektive false

	void report();		   //vypise obsah fronty
	
	void clear(); //odstraneni vsech prvku z fronty

	~linkedQueue();
};
