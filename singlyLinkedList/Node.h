#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
	private:
		T data;
		Node<T>* next;
	public:
		Node();
		Node(T value, Node<T>* newNext=0); // set next to null if not given
		~Node();

		T getData();
		Node<T>* getNext();
		void setData(T newData);
		void setNext(Node<T>* newNext=0);
};

#endif