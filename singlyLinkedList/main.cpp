#include "Node.h"
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
void deleteNode(Node<T>* head, Node<T>* target)
{
	if(head == NULL || target == NULL)
	{
		cout << "Nothing to delete" << endl;
		return ;
	}
	if(head == target) // want to delete head
	{
		delete head;
		return;
	}
	Node<T>* prev = head; // will point to node before target node
	Node<T>* it = head->getNext();
	while(it != NULL)
	{
		if(it == target)
		{
			prev->setNext(it->getNext()); // have prev point to target's next
			delete it;
			return;
		}else
		{
			prev = prev->getNext();
			it = it->getNext();
		}
	}
	cout << "Target not in list" << endl;
	return;
}

template <typename T>
void printList(Node<T>* head)
{
	Node<T>* iterator = head;
	while(iterator != NULL)
	{
		cout << iterator->getData() << " ";
		iterator = iterator->getNext();
	}
	cout << endl;
}

int main()
{
	Node<char>* five = new Node<char>('e');
	Node<char>* four = new Node<char>('d', five);
	Node<char>* three = new Node<char>('c', four);
	Node<char>* two = new Node<char>('b', three);
	Node<char>* one = new Node<char>('a', two);
	cout << "List: "; printList(one);
	cout << "Delete: c" << endl;
	deleteNode(one, three);
	cout << "List: "; printList(one);
	cout << "Delete: e" << endl;
	deleteNode(one, five);
	cout << "List: "; printList(one);

	return 0;
}