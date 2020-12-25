#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include <vector>
#include <list>

using namespace std;

template <class T>
class BubbleSort {
    private:
        void swap( vector<T> &, int, int ); // Funcion para intercambiar posiciones
    public:
        void bubbleSort( vector<T> & ); // Algoritmo de ordenamiento de burbuja
};

/*
    Funcion para intercambiar la posicion de dos elementos
    @param v Direccion del vector a trabajar
    @param i indice de un elemento a intercambiar
    @param j indice del otro elemento a intercambiar
*/
template <class T>
void BubbleSort<T>::swap( vector<T> &v, int i, int j ){
    T temp = v[i];
    v[i] = v[j];
    v[j] = v[temp];
}

/*
    Ordenamiento de burbuja
    @param v direccion del vector a ordenar
    @return Nada pero modifica el vector y lo ordena
*/
template <class T>
void BubbleSort<T>::bubbleSort( vector<T> &v )
{
    for ( int i = v.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if ( v[j] > v[j+1] ){
                swap(v, j, j+1)
            }
            
        }
    }
    return;
}

#endif /* BUBBLE_SORT_H_ */