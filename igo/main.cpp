#include <iostream>

#include "indigo.h"

using namespace std;


int main()
{
    Indigo::Indigo indigo;

    cout << "starting theads" << endl;

    indigo.startThreads();
    indigo.loadPackage("main");
    indigo.waitComplete();

    return 0;
}

