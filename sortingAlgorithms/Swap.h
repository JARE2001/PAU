#ifndef SWAP_H
#define SWAP_H

#include <vector>

using namespace std;

/*
    Funcion para intercambiar la posicion de dos elementos
    @param v Direccion del vector a trabajar
    @param i indice de un elemento a intercambiar
    @param j indice del otro elemento a intercambiar
*/
template <class T>
void swap( vector<T> &v, int i, int j ){
    T temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#endif