#include <vector>
#include <iostream>
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;

int main (){
    vector<int> v = {0};
    v = {7,6,5,4,3,2,1};
    mergeSort(v);
    for (int i = 0; i < v.size(); i++){
        if (i != 0) cout<< ", ";
        cout << v[i] ;
    }
    cout<< endl;
    return 0;
}