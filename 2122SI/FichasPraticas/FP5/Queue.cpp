#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

void Queue::put(Element* elem) {

	Node* newNode = new Node(elem);
	newNode->setNext(NULL);

	if (firstNode == NULL) {
		firstNode = newNode;
	}
	else {
		lastNode->setNext(newNode);
	}

	lastNode = newNode;
}


Element* Queue::get() {

	if (isEmpty())
		return NULL;

	Node* aux = firstNode;
	Element* elem = aux->getElement();

	firstNode = aux->getNext();
	delete aux;
	return elem;
}

bool Queue::isEmpty()
{
	return firstNode == NULL;
}


Queue::~Queue(void)
{
	while (!isEmpty()) {
		delete get();
	}
}



