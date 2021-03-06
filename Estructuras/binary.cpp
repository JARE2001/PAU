#include <iostream>

using namespace std;

int binarySearch( int arr[6], int n ) {
    int low = 0, high = 5, mid;
    while (low <= high){
        mid = (low + high) / 2;
        if (arr[mid] == n){
            return mid;
        }
        else if (n < arr[mid] ){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main (){
    int arreglo[6] = {1,3,6,7,9,10};
    int n = 1;
    cout << binarySearch(arreglo, n) << endl;

    return 0;
}