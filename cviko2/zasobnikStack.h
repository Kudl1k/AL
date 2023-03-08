#pragma once
#include <iostream>
using namespace std;

class arrayStack{
    private:
        int size;
        int* data;
        int sp; //stackpointer
    public:
        arrayStack(int n);
        ~arrayStack();
        bool isFull();
        bool isEmpty();
        bool push(int x);
        bool pop(int& x);

        void report();
};