#include <iostream>

using namespace std;


int main (){
    int *ptr;
    int arreglo[6] = {1,3,6,7,9,10};

    ptr =  arreglo;

    cout << *(arreglo + 4) << endl;
    cout << arreglo[4] << endl;
    cout << ptr << endl;
    cout << *ptr << endl;

    return 0;
}

