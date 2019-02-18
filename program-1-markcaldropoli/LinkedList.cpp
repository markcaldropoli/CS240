#include "LinkedList.h"
#include "Ant.h"
#include <cstddef>
#include <iostream>

using namespace std;

//Constructor
Node::Node(Ant * ant) {
	this->ant = ant;
	this->next = NULL;
}

//Constructor
LinkedList::LinkedList() {
	this->head = this->current = NULL;
}

//Copy Constructor
LinkedList::LinkedList(const LinkedList &other) {
	for(Node * tempNode = other.head; tempNode != NULL; tempNode = tempNode->next) {
		this->add(new Ant(*(tempNode->ant)));
	}
}

//Destructor
LinkedList::~LinkedList() {
	this->reset();
	Node * tempNode;

	while(this->current) {
		tempNode = this->current->next;
		delete this->current;
		this->current = tempNode;
	}
}

//Adds an ant to the LinkedList
void LinkedList::add(Ant* ant) {
	this->reset();

	if(!this->head) {
		this->head = new Node(ant);
		this->reset();
		return;
	}

	while(this->next()) this->get();

	this->current->next = new Node(ant);
	this->reset();
	return;
}

//Removes an ant from the LinkedList
bool LinkedList::remove(int id) {
	this->reset();
	if(!head) return false;

	if(current->ant->getID() == id) {
		Node * tempNode = current;
		head = current->next;

		delete tempNode;
		reset();
		return true;
	}

	while(this->next()) {
		if(current->next->ant->getID() == id) {
			Node * tempNode = current->next;
			current->next = tempNode->next;

			delete tempNode;
			this->reset();
			return true;
		}
		current = current->next;
	}
	return false;
}

//Gets an ant from the LinkedList
Ant * LinkedList::get(int id) {
	this->reset();

	while(this->current) {
		if(current->ant->getID() == id) {
			Ant * tempAnt = current->ant;
			this->reset();
			return tempAnt;
		}
		current = current->next;
	}
	reset();
	return NULL;
}

//Gets the current ant and updates current
Ant * LinkedList::get() {
	if(!head || !current) return NULL;

	Ant * tempAnt = current->ant;
	current = current->next;
	return tempAnt;
}

//Gets the current ant (no update)
Ant * LinkedList::getCurrent() {
	if(current) return this->current->ant;
	return NULL;
}

//Gets the next ant (no update)
Ant * LinkedList::next() {
	if(current && current->next) return current->next->ant;
	return NULL;
}

//Sets current to head
void LinkedList::reset() {
	this->current = this->head;
	return;
}

//Adds an ant to the LinkedList
void LinkedList::operator<<(Ant * a) {
	this->add(a);
	return;
}
