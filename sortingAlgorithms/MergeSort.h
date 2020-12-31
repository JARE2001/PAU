#include <vector>
using namespace std;

template <class T>
void copyArray( vector<T> &A, vector<T> &B, int low, int high ){
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}


template <class T>
void merge( vector<T> &A, vector<T> &B, int low, int mid, int high ){
    int i = low;
    int j = mid + 1;
    int k = low;

    while ( i <= mid && j <= high )
    {
        if ( A[i] < A[j] ) { 
            B[k] = A[i];
            i++;
        }

        else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    if ( i > mid ) {
        for ( ; j <= high; j++ ) {
            B[k] = A[j];
            k++;
        }
    }
    else {
        for (; i <= mid; i++ ) {
            B[k] = A[i];
            k++;
        }
    }
}


template <class T>
void splitMerge( vector<T> &v, vector<T> &B, int low, int high ){
    if( high-low < 1 ) return;

    int mid = (low + high) / 2;

    splitMerge( v, B, low, mid ); 
    splitMerge( v, B, mid+1, high ); 
    merge( v, B, low, mid, high );
    copyArray( v, B, low, high );
}

template <class T>
void mergeSort( vector<T> &v ){
    vector<T> temp( v.size() );
    splitMerge( v, temp, 0, v.size()-1 );
}
