#pragma once
//zasobnik pro ulozeni celych cisel
class arrayStack
{
private:
	static const int velikost = 50;  //kapacita zasobniku
	int data[velikost];  //pole dat, ukladame cela cisla typu int
	int vrchol; //ukazatel na vrchol zasobniku (na prvni volnou pozici)
public:
	arrayStack();

	//inicializuje zasobnik (nastavi hodnotu promenne vrchol na 0)
	void init();

	//vraci true pokud je zasobnik prazdny
	//v opacnem pripade vraci false
	bool isEmpty();

	//vraci true pokud je zasobnik plny
	//v opacnem pripade vraci false
	bool isFull();

	//vlozi cislo x na vrchol zasobniku
	//vraci true kdyz vlozeni probehlo uspesne, false kdyz nikoliv (zasobnik byl plny)
	bool push(int x);

	//odebere prvek z vrcholu zasobniku a ulozi do promenne x
	//vraci true kdyz odebrani probehlo uspesne, false kdyz nikoliv (zasobnik byl prazdny) 
	bool pop(int& x);

	//funkce ktera precte hodnotu prvku na vrcholu zasobniku a ulozi do promenne x bez jeho odebrani
	//vraci true kdyz precteni probehlo uspesne, false kdyz nikoliv (zasobnik byl prazdny) 
	bool top(int& x);

	//funkce pro kontrolu spravne funkcnosti zasobníku
	//vypise hodnotu ukazatele na vrchol
	//pokud je zasobnik prazdny nebo plny vypise tuto informaci
	//vypise obsah zasobniku 
	void report();
};
