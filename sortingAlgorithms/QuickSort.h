#ifndef QUICK_H
#define QUICK_H

#include <vector>
#include <iostream>
#include "Swap.h"
using namespace std;

template <class T>
int quickPartition( vector<T> &v, int low, int high) {
    T pivot = v[high];
    int i = low-1;
    for (int j = low; j < high ; j++) {
        if (v[j] <= pivot) {
            i++;
            swap (v, i, j ); 
        }
    }
    swap(v, i+1, high);
    return (i+1); 
}

template <class T>
void quickHelper(vector<T> &v, int low, int high ) {
    if (low < high) {
        int pivot = quickPartition( v, low, high);
        quickHelper( v, low, pivot-1);
        quickHelper( v, pivot+1, high); 
    }
}

template <class T>
void quickSort(vector<T> &V) {
    quickHelper (V, 0, V.size()-1);
}


#endif