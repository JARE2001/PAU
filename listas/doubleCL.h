#ifndef DOUBLE_CL_H
#define DOUBLE_CL_H
#include <sstream>

using namespace std;

template <class T> class doubleCL;

template <class T>
class NodeCD 
{
    private:
        T value;
        NodeCD<T> *next;
        NodeCD<T> *prev;
    public:
        NodeCD( T val);
         ~NodeCD();
    friend class doubleCL<T>;
};
template <class T>
NodeCD<T> :: NodeCD(T val){
    value = val;
    next = NULL;
    prev = NULL;
}

template <class T>
class doubleCL
{
    private:
        NodeCD<T> *head;
        int size;
    public:
        doubleCL();
        ~doubleCL();
        void addFirst( T val );
        void addLast( T val );
        void addAt( int pos, T val );
        string toString();
};

template <class T>
doubleCL<T> :: doubleCL() {
    head = NULL;
    size = 0;
}

template <class T>
doubleCL<T> :: ~doubleCL(){
}

template <class T>
void doubleCL<T> :: addFirst( T val ){
    NodeCD<T> *node = new NodeCD<T>(val);

    node -> next = head;
    if ( size == 0 ) {
        node -> prev = node;
        node -> next = node;
    }
    else {  
        node -> prev = head -> prev;
        head -> prev ->next = node;
        head -> prev = node;
        
    }
    head = node;
    size++;
}

template <class T>
void doubleCL<T> :: addLast( T val ){
    NodeCD<T> *node = new NodeCD<T>(val), *curr;
    curr = head;
    while (curr -> next != head) {
        curr = curr -> next;
    }
    curr -> next = node;
    node -> prev = curr;
    node -> next = head;
    head -> prev = node;
    size++;
}

template <class T>
void doubleCL<T> :: addAt( int pos, T val ){
    if ( pos < 0 || pos > size ) 
        return;

    if ( pos==0 )
        addFirst(val);
    
    else if ( pos == size )
        addLast(val);

    else {
        NodeCD<T> *node = new NodeCD<T>(val), *curr; 
        curr = head;
        for ( int i = 0; i < pos; i++ ) {
            curr = curr -> next;
        }
        node -> prev = curr -> prev;
        node -> next = curr;
        curr -> prev -> next = node;
        curr -> prev = node;
    }
    size++;
}

template <class T>
string doubleCL<T> :: toString(){
    stringstream aux; 
    NodeCD<T> *current;
    current = head;
    bool first = true;
    while ( current != head || first )
    {
        if (first)
            first = false;
        aux << current -> value << " ";
        current = current -> next;
    }
    return aux.str();
}

#endif