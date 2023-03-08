#include "zasobnikStack.h"

#include <iostream>
using namespace std;


int main(){
    arrayStack stack(5);

    stack.push(1);
    stack.push(5);
    stack.push(7);

    stack.report();

    return 0;
}