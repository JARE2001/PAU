#include <iostream>
#include "simpleL.h"
#include "doubleL.h"
#include "doubleCL.h"

using namespace std;

int main(int argc, char const *argv[])
{
    simpleL<int> lista;
    lista.addFirst(9);
    lista.addFirst(3);
    lista.addFirst(7);
    lista.addAt(3,5);
    cout << lista.toString() << endl;
    
    doubleL<int> listaD;
    listaD.addFirst(9);
    listaD.addFirst(3);
    listaD.addFirst(7);
    listaD.addAt(3,5);
    cout << listaD.toString() << endl;

    doubleCL<int> listaCD;
    listaCD.addFirst(9);
    listaCD.addFirst(3);
    listaCD.addFirst(7);
    listaCD.addAt(2,5);
    cout << listaCD.toString() << endl;

    return 0;
}