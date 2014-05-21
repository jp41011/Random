#include <iostream>
#include "Node.h"
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename T>
bool isLoopFree(Node<T>* head)
{
	if(head == NULL)
		return true;
	Node<T>* slow = head; // slow iterator will move 1 step forward
	if(head->getNext() == NULL) // only one node
		return true;
	Node<T>* fast = head->getNext(); // fast iterator will move 2 steps forward

	while(slow != fast)
	{
		if(fast == NULL || fast->getNext() == NULL) // reached an end
			return true;
		fast = fast->getNext()->getNext();
		slow = slow->getNext();
	}
	return false;
}

// assumes that N = 1 -> last element, N=2 -> 2nd last element ...
template <typename T>
Node<T>* NFromLast(Node<T>* head, int N)
{
	if(N < 1)
	{
		cout << "Error: 1 is the minimum" << endl;
		return NULL;
	}
	Node<T>* target = head;
	Node<T>* canary = head;
	int count = 0;
	while(canary != NULL && count < N)
	{
		canary = canary->getNext();
		count ++;
	}
	if(count != N)
	{
		cout << "List was too short" << endl;
		return NULL;
	}
	while(canary != NULL)
	{
		target = target->getNext();
		canary = canary->getNext();
	}
	return target;
}

template <typename T>
void printForward(Node<T>* head) // does not need to be called with head of list
{
	Node<T>* temp = head;
	cout << "List forward: ";
	while(temp != NULL)
	{
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}
	cout << endl;
}

template <typename T>
void printBackward(Node<T>* tail) // does not need to be actual tail of list
{
	Node<T>* temp = tail;
	cout << "List backward: ";
	while(temp != NULL)
	{
		cout << temp->getData() << " ";
		temp = temp->getPrev();
	}
	cout << endl;
}

int main()
{
	Node<char>* one = new Node<char>('a');
	Node<char>* two = new Node<char>('b',one);
	Node<char>* three = new Node<char>('c',two);
	Node<char>* four = new Node<char>('d',three);
	Node<char>* five = new Node<char>('e', four);
	Node<char>* six = new Node<char>('f', five);
	Node<char>* seven = new Node<char>('g', six);
	seven->setNext(three);
	//printForward(one);
	//printBackward(seven);
	// there is a look a->b->c->d->e->f->g->c (only one c)
	
	Node<char>* single = new Node<char>('I');
	single->setNext(single);

	cout << "Loop Free: ";
	if(isLoopFree(one))//if(isLoopFree(single))
		cout << "True";
	else
		cout << "False";
	cout << endl;

	// remove the loop
	seven->setNext(NULL);
	cout << "Removed loop" << endl;
	printForward(one);
	cout << "Loop Free?: ";
	if(isLoopFree(one))//if(isLoopFree(single))
		cout << "True";
	else
		cout << "False";
	cout << endl;

	cout << "1st from last: " << NFromLast(one, 1)->getData() << endl;
	cout << "3rd from last: " << NFromLast(one, 3)->getData() << endl;
	cout << "7th from last: " << NFromLast(one, 7)->getData() << endl;
	//cout << "8th from last: " << NFromLast(one, 8)->getData() << endl; // should cause error
	//cout << "0th from last: " << NFromLast(one, 0)->getData() << endl; // should cause error
	
	// remove single's next
	single->setNext(NULL);
	cout << "single node: " << NFromLast(single, 1)->getData() << endl;

	Node<char>* oneTwo = new Node<char>('1');
	Node<char>* twoOne = new Node<char>('2',oneTwo);
	printForward(oneTwo);
	cout << "last: " << NFromLast(oneTwo, 1)->getData() << endl;
	cout << "2nd last: " << NFromLast(oneTwo, 2)->getData() << endl;

	/* Testing Node with different types
	Node<char>* c1 = new Node<char>();
	cout << "c1: " << c1->getData() << endl;
	Node<char>* c2 = new Node<char>('c');
	cout << "c2: " << c2->getData() << endl;
	Node<int>* i1 = new Node<int>();
	cout << "i1: " << i1->getData() << endl;
	Node<int>* i2 = new Node<int>(1);
	cout << "i2: " << i2->getData() << endl;
	*/
	/* Testing typeid
	cout << "Bool: " << typeid(bool).name() << endl;
	cout << "Char: " << typeid(char).name() << endl;
	cout << "String: " << typeid(string).name() << endl;
	cout << "Short: " << typeid(short).name() << endl;
	cout << "Int: " << typeid(int).name() << endl;
	cout << "Long: " << typeid(long).name() << endl;
	cout << "Float: " << typeid(float).name() << endl;
	cout << "Double: " << typeid(double).name() << endl;
	*/

	return 0;
}