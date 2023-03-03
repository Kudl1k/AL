#include "arrayStack.h"
#include <iostream>

using namespace std;

arrayStack::arrayStack()
{
	init();
}

void arrayStack::init()
{
	vrchol = 0;
}

bool arrayStack::isEmpty()
{
	return vrchol == 0;
}

bool arrayStack::isFull()
{
	return vrchol == velikost;
}

bool arrayStack::push(int x)
{
	if (isFull())
		return false;
	else
	{
		data[vrchol++] = x;
		return true;
	}
}

bool arrayStack::pop(int& x)
{
	if (isEmpty())
		return false;
	else
	{
		x = data[--vrchol];
		return true;
	}
}

bool arrayStack::top(int& x)
{
	if (isEmpty())
		return false;
	else
	{
		x = data[vrchol];
		return true;
	}
}

void arrayStack::report()
{
	if (isEmpty())
		cout << "Zasobnik je prazdny!" << endl;
	if (isFull())
		cout << "Zasobnik je prazdny!" << endl;
	cout << "Hodnota ukazatele na vrchol je: " << vrchol << "." << endl;
	cout << "Hodnoty ulozene na zasobniku:" << endl << endl;
	for (int i = vrchol - 1; i >= 0; i--)
	{
		if (i == vrchol - 1)
			cout << "Vrchol zasobniku" << endl;
		
		cout << data[i] << endl;
		if (i == 0)
			cout << "Dno zasobniku"<<endl<<endl;
	}
}