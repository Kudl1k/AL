#include "zasobnikStack.h"

arrayStack::arrayStack(int n){
    size = n;
    data = new int[size]; //dynamická alokace
    sp = 0;
}

arrayStack::~arrayStack(){
    delete[] data;
}

bool arrayStack::isFull(){
    return sp==size;
}
bool arrayStack::isEmpty(){
    return sp==0;
}

bool arrayStack::push(int x){
    if (isFull()) return false;
    data[sp++] = x;
    return true;
}

bool arrayStack::pop(int& x){
    if (isEmpty()) return false;
    x = data[--sp];
    return true;
}

void arrayStack::report(){
    cout << "Velikost zásobníku: " << size << endl;
    cout << "Stackpointer: " << sp << endl;
    cout << "Zásobník: ";
    for (int i = 0; i < sp; i++) cout << data[i] << " ";
    cout << endl;
}