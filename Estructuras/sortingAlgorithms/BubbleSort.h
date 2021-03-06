#ifndef BUBBLE_H
#define BUBBLE_H

#include <vector>
#include <iostream>

using namespace std;
/*
    Ordenamiento de burbuja
    @param v direccion del vector a ordenar
    @return Nada pero modifica el vector y lo ordena
*/
template <class T>
void bubbleSort( vector<T> &v )
{
   
    for ( int i = v.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if ( v[j] > v[j+1] ){
                swap(v, j, j + 1) ;
            }
        }
    }
}

#endif