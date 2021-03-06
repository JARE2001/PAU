#ifndef INSERTION_H
#define INSERTION_H

#include <vector>
#include "Swap.h"
using namespace std;


template <class T>
void insertionSort( vector<T> &v ) {

    for ( int i = 1 ; i < v.size() ; i++ ) { 

        for ( int j = i; j>0 && v[j] < v[j-1]; j-- ) {
            swap( v, j, j-1 ); 
        }
    }
}

#endif