#ifndef SELECTION_H
#define SELECTION_H

#include <vector>
#include "Swap.h"

/*
    Funcion para intercambiar la posicion de dos elementos
    @param v Direccion del vector a trabajar
    @param i indice de un elemento a intercambiar
    @param j indice del otro elemento a intercambiar
*/
template <class T>
void selectionSort( vector<T> &v ) {
    int pos;
    
    for (int i = v.size()-1; i > 0 ; i-- )  {
        pos = 0 ;

        for ( int j = 1 ; j <= i ; j++ ) {
            if ( v[ j ] > v[pos] ) {
                pos = j ;
            }
        }
        if (pos != i){
            swap(v, pos, i);
        }
    }
}

#endif