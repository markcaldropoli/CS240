#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <class V>
class Queue {
	private:
		LinkedList<V> * queue;
	public:
		Queue<V>();
		~Queue<V>();
		bool enqueue(V data);
		V dequeue();
		V peek();
		bool empty();
		void clear();
};

template <class V>
Queue<V>::Queue() {
	this->queue = new LinkedList<V>();
}

template <class V>
Queue<V>::~Queue() {
	delete this->queue;
}

template <class V>
bool Queue<V>::enqueue(V data) {
	this->queue->insert(data);
	return true;
}

template <class V>
V Queue<V>::dequeue() {
	this->queue->reset();
	V ret = this->queue->read();
	this->queue->remove(ret);
	return ret;
}

template <class V>
V Queue<V>::peek() {
	this->queue->reset();
	return this->queue->read();
}

template <class V>
bool Queue<V>::empty() {
	return this->queue->empty();
}

template <class V>
void Queue<V>::clear() {
	this->queue->reset();

	while(this->queue->next()) {
		this->queue->remove(this->queue->read());
	}
}

#endif
