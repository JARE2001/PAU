#include <iostream>
#include "arbolesB.h"

using namespace std;

int main() {
    ArbolB<int> arbolito;
    arbolito.add(5);
    arbolito.add(4);
    arbolito.add(2);
    arbolito.add(1);
    arbolito.add(10);
    cout << arbolito.inOrder() << endl;
}