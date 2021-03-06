#include <iostream>

using namespace std;


int main (){
    int *ptr;
    int arreglo[6] = {1,3,6,7,9,10};
    ptr = arreglo;

    cout << *(arreglo + 4) << endl;
    cout << arreglo[4] << endl;
    cout << &arreglo << endl;
    cout << ptr << endl;
    cout << *ptr << endl;

    // Pruebas que hizo Pau ignorar xd
    cout << *arreglo << endl;
    cout << "\n" << arreglo[0] << endl;

    ptr[0] = 2;
    cout << "\n" << arreglo[0] << endl;

    return 0;
}

 