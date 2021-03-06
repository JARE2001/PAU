#ifndef ARBOL_B_H
#define ARBOL_B_H

#include <sstream>

using namespace std;
//hola
template <class T> class ArbolB;

template <class T>
class Node
{
    private:
        Node<T> *left, *right;
        T value;
        void add(T val, int &size);
        void inOrder(stringstream &aux);

    public:
        Node();
        Node(T val);

        friend class ArbolB<T>;
};

template <class T>
class ArbolB
{
    private:
        Node<T> *root;
        int size;

    public:
        ArbolB();
        void add(T val);
        string inOrder();
};

template <class T>
Node<T>::Node()
{
    value = NULL;
    left = NULL;
    right = NULL;
}

template <class T>
Node<T>::Node(T val)
{
    value= val;
    left = NULL;
    right = NULL;
}
template <class T>
ArbolB<T>::ArbolB()
{
    root = NULL;
    size = 0;
}

template <class T>
void ArbolB<T>::add(T val)
{
    if(size == 0) {
        root = new Node<T>(val);
        size++;
    }
    else
        root->add(val,size);
}

template <class T>
void Node<T>::add(T val, int &size)
{
    if(val < value){
        if(left == NULL) {
            size++;
            left = new Node<T>(val);
        }
        else
            left->add(val,size);
    }
    else if( val > value){
        if(right == NULL){
            size ++;
            right = new Node<T>(val);
        }
        else
            right->add(val,size);
    }
}

template <class T>
string ArbolB<T>::inOrder() {
    stringstream aux;

    aux << "[";
    if(size != 0)
        root->inOrder(aux);
    aux << "]";

    return aux.str();
}

template <class T>
void Node<T>::inOrder(stringstream &aux) {

    if(left != NULL) 
        left->inOrder(aux);
    
    aux << value << " ";
    
    if(right != NULL) 
        right->inOrder(aux);
}

#endif