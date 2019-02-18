#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>

template <class S>
class Node {
	public:
		S data;
		Node<S> * next;
		Node(S data);
};

template <class T>
class LinkedList {
	private:
		Node<T> * head;
		Node<T> * current;
	public:
		LinkedList();
		LinkedList(const LinkedList<T> &);
		~LinkedList();
		void insert(T data);
		T& read();
		bool empty();
		bool remove(T &data);
		void reset();
		bool next();
};

template <class S>
Node<S>::Node(S data) {
	this->data = data;
	this->next = NULL;
}

template <class T>
LinkedList<T>::LinkedList() {
	this->head = NULL;
	this->current = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) {
	for(Node<T> * tempNode = other.head; tempNode != NULL; tempNode = tempNode->next) {
		this->insert(T(*tempNode->data));
	}
}

template <class T>
LinkedList<T>::~LinkedList() {
	this->reset();
	Node<T> * tempNode;

	while(this->current) {
		tempNode = this->current->next;
		delete this->current;
		this->current = tempNode;
	}
}

template <class T>
void LinkedList<T>::insert(T data) {
	if(this->empty()) { 
		this->head = new Node<T>(data);
		this->reset();
		return;
	}

	this->reset();
	while(this->current->next) this->current = this->current->next;
	this->current->next = new Node<T>(data);
	this->reset();
	return;
}

template <class T>
T& LinkedList<T>::read() {
	T& ret = this->current->data;
	this->current = this->current->next;
	return ret;
}

template <class T>
bool LinkedList<T>::empty() {
	if(!this->head) return true;
	return false;
}

template <class T>
bool LinkedList<T>::remove(T &data) {
	if(this->empty()) return false;

	if(this->head->data == data) {
		Node<T> * tempNode = this->head;
		this->head = this->head->next;
		delete tempNode;
		this->reset();
		return true;
	}

	this->reset();

	while(this->current->next) {
		if(this->current->next->data == data) {
			Node<T> * tempNode = this->current->next;
			this->current->next = tempNode->next;
			delete tempNode;
			this->reset();
			return true;
		}
		this->current = this->current->next;
	}

	return false;
}

template <class T>
void LinkedList<T>::reset() {
	this->current = this->head;
	return;
}

template <class T>
bool LinkedList<T>::next() {
	return (this->current != NULL);
}

#endif
