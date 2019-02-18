#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Ant.h"

class Node {
	public:
		Ant * ant;
		Node(Ant *);
		Node * next;
};

class LinkedList {
	private:
		Node * head;
		Node * current;
	public:
		//Default Constructor, Copy Constructor, Destructor
		LinkedList();
		LinkedList(const LinkedList &);
		~LinkedList();
		//Operator Overload
		void operator<<(Ant *);
		//CRUD Operations
		void add(Ant *);
		bool remove(int);
		Ant * get(int);
		Ant * get();
		Ant * next();
		Ant * getCurrent();
		void reset();
};

#endif
