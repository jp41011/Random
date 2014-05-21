#include "Node.h"
#include <typeinfo>

template <typename T>
inline
Node<T>::Node()
{
	if(typeid(T) == typeid(char))
		data = '~';
	else
		data = 0;
	
	prev = 0; // NULL
	next = 0;
}

template <typename T>
Node<T>::Node(T value, Node<T>* prevNode, Node<T>* nextNode)
{
	data = value;
	prev = prevNode;
	next = nextNode;
	if(prev != 0) // if prev ptr not null
		prev->next = this;
	if(next != 0) // if next is not null
		next->prev = this; 
}

template <typename T>
Node<T>::~Node(){ }

template <typename T>
T Node<T>::getData(){ return data; }

template <typename T>
Node<T>* Node<T>::getPrev(){ return prev; }

template <typename T>
Node<T>* Node<T>::getNext(){ return next; }

template <typename T>
void Node<T>::setPrev(Node<T>* node){ prev = node; }

template <typename T>
void Node<T>::setNext(Node<T>* node){ next = node; }

// explicitly instantiating char and int 
template class Node<char>;
template class Node<int>;