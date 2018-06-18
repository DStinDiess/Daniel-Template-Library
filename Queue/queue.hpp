#include <stdexcept>

#ifndef __DSD_Queue__
#define __DSD_queue__

template <typename T>
struct node {
	T data;
	node* next;
	node* prev;

	node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Queue {
 private:
 	node<T>* _head;
 	node<T>* _tail;
 	unsigned _size;

 public:
	Queue();

	bool empty();
	unsigned size();
	void enqueue(T);
	void dequeue();
	T front();
};

template <typename T>
Queue<T>::Queue() : _head(nullptr), _size(0) {}

template <typename T>
bool Queue<T>::empty() {
	return this->_size == 0;
}

template <typename T>
unsigned Queue<T>::size() {
	return this->_size;
}

template <typename T>
void Queue<T>::enqueue(T val) {
	node<T>* new_node = new node<T>(val);
	if (!this->_head) {
		this->_head = new_node;
		this->_tail = new_node;
	} else {
		this->_head->prev = new_node;
		new_node->next = this->_head;
		this->_head = new_node;
	}
	this->_size++;
}

template <typename T>
void Queue<T>::dequeue() {
	if (this->_tail) {
		node<T>* new_tail = this->_tail->prev;
		
		delete this->_tail;
		this->_tail = new_tail;
		if (this->_tail) {
			this->_tail->next = nullptr;
		}
		this->_size--;
	} else {
		throw std::out_of_range("Called dequeue on an empty queue.");
	}
}

template <typename T>
T Queue<T>::front() {
	return this->_tail->data;
}

#endif