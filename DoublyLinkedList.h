/* Jack Donnelly
2342203
CPSC 350-02
Assignment 5
*/
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include "Student.h"
#include "ListNode.h"
#include "ListADT.h"
using namespace std;

template <typename T>
class DoublyLinkedList : ListADT<T>
{
	private:
		size_t size;

	public:
		ListNode<T> *back;
		ListNode<T> *front;
		DoublyLinkedList();
		~DoublyLinkedList();

		virtual void insertFront(T d);
		virtual void insertBack(T d);
		virtual void printList(bool printLink);
		virtual T peekFront();
		virtual T peekBack();
		virtual T removeFront();
		virtual T removeBack();
		virtual T remove(T key);
		virtual int find(T key);
		bool isEmpty();
		virtual size_t getSize();


};
#endif

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	front = NULL;
	back = NULL;
	size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	ListNode<T>* ptr = front;
	ListNode<T>* nextNode;

	while (ptr != NULL) {
		nextNode = ptr->next;
		delete ptr;

		ptr = nextNode;
	}
}

template <typename T>
T DoublyLinkedList<T>::peekFront() {
	return front->data;
}

template <typename T>
T DoublyLinkedList<T>::peekBack() {
	return back->data;
}

template <typename T>
void DoublyLinkedList<T>::insertFront(T d) {
	ListNode<T> *node = new ListNode<T>(d);

	if (size == 0) {
		back = node;
	}
	else {
		node->next = front;
		front->prev = node;
	}
	front = node;
	size++;
}

template <typename T>
void DoublyLinkedList<T>::insertBack(T d) {
	ListNode<T> *node = new ListNode<T>(d);

	if (size == 0) {
		front = node;
	}
	else {
		back->next = node;
		node->prev = back;
	}
	back = node;
	size++;
}

template <typename T>
T  DoublyLinkedList<T>::removeFront() {
	if (isEmpty()) {
		throw runtime_error("Can't remove from empty list.");
	}
	ListNode<T> *tp = front;
	if (front->next == NULL) {
		back = NULL;
	}
	else {
		front->next->prev = NULL;
	}
	front = tp->next;
	tp->next = NULL;
	T temp = tp->data;
	size--;
	delete tp;
	return temp;
	
}

template <typename T>
T DoublyLinkedList<T>::removeBack() {
	if (isEmpty()) {
		throw runtime_error("Can't remove from empty list.");
	}
	ListNode<T>* tp = back;
	if (back->prev == NULL) {
		front = NULL;
	}
	else {
		back->prev->next = NULL;
	}
	back = tp->prev;
	tp->next = NULL;
	tp->prev = NULL;
	T temp = tp->data;
	delete tp;
	return temp;

}

template <typename T>
int DoublyLinkedList<T>::find(T key) {
	int idx = -1;
	ListNode<T> *current = front;
	while (current != NULL)
	{
		++idx;
		if (current->data == key) {
			break;
		}
		else {
			current = current->next;
		}
	}
	if (current == NULL) {
		idx = -1;
	}
	return idx;
}



template <typename T>
T DoublyLinkedList<T>::remove(T key) {
	ListNode<T> *current = front;
	while (current->data != key) {
		current = current->next;
		if (current == NULL) {
			cout << "Could not remove because node doesn't exist." << endl;
			return key;
		}
	}
	if (current == front) {
		front = front->next;
		if (front != NULL) {
			front->prev = NULL;
		}
	}
	else if (current == back) {
			back = back->prev;
			back->next = NULL;
	}
	else{
		current->next->prev = current->prev;
		current->prev->next = current->next;
	}
	T temp = current->data;
	size--;
	delete current;

	return temp;

}

template <typename T>
size_t DoublyLinkedList<T>::getSize() {
	return size;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() {
	return size == 0;
}

template <typename T>
void DoublyLinkedList<T>::printList(bool printLink)
{
	ListNode<T>* curr = front;
	while (curr != NULL) {
		if (curr == front) {
			cout << "{FRONT}: ";
		}
		else if (curr == back) {
			cout << "{REAR}: ";
		}
		if (printLink)
			cout << "[ PREV: " << curr->prev << " || " << curr->data << " || NEXT: " << curr->next << " ] ";
		else
			cout << "[ " << curr->data << " ] ";

		curr = curr->next;
		if (curr != NULL) {
			cout << " ==> ";
		}
	}
	cout << endl;
}





