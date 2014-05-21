#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
	T data;
	Node* prev;
	Node* next;
public:
	Node();
	Node(T value, Node<T>* prevNode=0, Node<T>* nextNode=0);
	~Node();

	T getData();
	Node<T>* getPrev();
	Node<T>* getNext();
	void setPrev(Node<T>*);
	void setNext(Node<T>*);

};

#endif