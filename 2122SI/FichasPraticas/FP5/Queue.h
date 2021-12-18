#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "StaticText.h"

class Element
{
private:
	time_t entrada;
	StaticText texto;
public:
	Element() { 
		entrada = time(NULL);
		struct tm* pGmt;
		pGmt = gmtime(&entrada);
		texto = StaticText::StaticText("Hora de Entrada");
	};
	time_t get() { return entrada; }
};

class Node
{
private:
	Node* next;
	Element* elem;

public:
	Node(void) { next = NULL; }
	Node(Element* e) { elem = e; }
	~Node(void) {}

	void setNext(Node* n) { next = n; }
	Node* getNext() { return next; }
	Element* getElement() { return elem; }
};

class Queue {

private:
	Node* firstNode;	
	Node* lastNode;	
public:
	Queue() { firstNode = NULL; }
	~Queue();

	void put(Element* elem);
	Element* get();
	bool isEmpty();
};
