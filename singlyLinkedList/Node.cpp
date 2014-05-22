#include "Node.h"
#include <typeinfo>

template <typename T>
Node<T>::Node()
{
	if(typeid(T) == typeid(char))
		data = '0';
	else
		data = 0;
	next = 0;
}

template <typename T>
Node<T>::Node(T value, Node<T>* newNext)
{
	data = value;
	next = newNext;	
}

template <typename T>
Node<T>::~Node() { }

template <typename T>
T Node<T>::getData(){ return data; }

template <typename T>
Node<T>* Node<T>::getNext(){ return next; }

template <typename T>
void Node<T>::setNext(Node<T>* newNext)
{
	next = newNext;
}

// make sure initialized for char and int
template class Node<char>;
template class Node<int>;
// get compile error without theses. Could also put function definitions in the same
// file (header file) as the declarations