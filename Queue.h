/* Jack Donnelly
2342203
CPSC 350-02
Assignment 5
*/
#ifndef QUEUE_H
#define QUEUE_H

#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

template <typename T>
class Queue{
public:
	Queue();
	~Queue();

	//core functions
	void enqueue(T data);
	T dequeue();

	//aux functions
	T peek();
	void print();
	bool isEmpty();
	size_t getSize();

private:
	DoublyLinkedList<T>* queue;
};

#endif

template <typename T>
Queue<T>::Queue() {
	queue = new DoublyLinkedList<T>();
}

template <typename T>
Queue<T>::~Queue() {
	delete queue;
}

template <typename T>
void Queue<T>::enqueue(T data) {
	queue->insertBack(data);
}

template <typename T>
void Queue<T>::print() {
	queue->printList(false);
}

template <typename T>
T Queue<T>::dequeue() {
	return queue->removeFront();
}

template <typename T>
T Queue<T>::peek() {
	return queue->peekFront();
}

template <typename T>
size_t Queue<T>::getSize() {
	return queue->getSize();
}

template <typename T>
bool Queue<T>::isEmpty() {
	return queue->isEmpty();
}

