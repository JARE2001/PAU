#ifndef SIMPLE_L_H
#define SIMPLE_L_H
#include <sstream>

using namespace std;

template <class T> class simpleL;

template <class T>
class Node 
{
    private:
        T value;
        Node<T> *next;
    public:
        Node( T val);
        Node( T val, Node<T> *nxt );
        ~Node();
    friend class simpleL<T>;
};
template <class T>
Node<T> :: Node(T val){
    value = val;
    next = NULL;
}

template <class T>
Node<T> :: Node( T val, Node<T> *nxt ){
    value = val;
    next = nxt;
}

template <class T>
class simpleL
{
    private:
        Node<T> *head;
        int size;
    public:
        simpleL();
        ~simpleL();
        void addFirst( T val );
        void addAt( int pos, T val );
        string toString();
};

template <class T>
simpleL<T> :: simpleL() {
    head = NULL;
    size = 0;
}

template <class T>
simpleL<T> :: ~simpleL(){
}

template <class T>
void simpleL<T> :: addFirst( T val ){
    Node<T> *node = new Node<T>(val);

    node->next = head;
    head = node;
    size++;
}

template <class T>
void simpleL<T> :: addAt( int pos, T val ){
    if ( pos < 0 || pos > size ) 
        return;
    if ( pos==0 )
        addFirst(val);

    Node<T> *node = new Node<T>(val), *curr, *prev; 
    curr = head;
    for ( int i = 0; i < pos; i++ ) {
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = node;
    node -> next = curr;
    size ++;
}

template <class T>
string simpleL<T> :: toString(){
    stringstream aux; 
    Node<T> *current;
    current = head;
    while (current != NULL)
    {
        aux << current -> value << " ";
        current = current -> next;
    }
    return aux.str();
}

#endif