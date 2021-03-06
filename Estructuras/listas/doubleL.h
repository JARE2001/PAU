#ifndef DOUBLE_L_H
#define DOUBLE_L_H
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class doubleL;

template <class T>
class NodeD 
{
    private:
        T value;
        NodeD<T> *next;
        NodeD<T> *prev;
    public:
        NodeD( T val);
        ~NodeD();
    friend class doubleL<T>;
};
template <class T>
NodeD<T> :: NodeD(T val){
    value = val;
    next = NULL;
    prev = NULL;
}

template <class T>
class doubleL
{
    private:
        NodeD<T> *head;
        int size;
    public:
        doubleL();
        ~doubleL();
        void addFirst( T val );
        void addLast( T val );
        void addAt( int pos, T val );
        string toString();
};

template <class T>
doubleL<T> :: doubleL() {
    head = NULL;
    size = 0;
}

template <class T>
doubleL<T> :: ~doubleL(){
}

template <class T>
void doubleL<T> :: addFirst( T val ){
    NodeD<T> *node = new NodeD<T>(val);

    node -> next = head;
    if ( size == 0 )
        node -> prev = NULL;
    else {  
        node -> prev = head -> prev;
        head -> prev = node;
    }
    head = node;
    size++;
}

template <class T>
void doubleL<T> :: addLast( T val ){
    NodeD<T> *node = new NodeD<T>(val), *curr;
    curr = head;
    while (curr -> next != NULL) {
        curr = curr -> next;
    }
    curr -> next = node;
    node -> prev = curr;
    size++;
}

template <class T>
void doubleL<T> :: addAt( int pos, T val ){
    if ( pos < 0 || pos > size ) 
        return;

    if ( pos==0 )
        addFirst(val);
    
    else if ( pos == size )
        addLast(val);

    else {
        NodeD<T> *node = new NodeD<T>(val), *curr; 
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
string doubleL<T> :: toString(){
    stringstream aux; 
    NodeD<T> *current;
    current = head;
    while (current != NULL)
    {
        aux << current -> value << " ";
        current = current -> next;
    }
    return aux.str();
}

#endif