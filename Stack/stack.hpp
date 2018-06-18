#include <stdexcept>

#ifndef __DSD_STACK__
#define __DSD_STACK__

template <typename T>
struct node {
	T data;
	node* next;
	node* prev;

	node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Stack {
 private:
 	node<T>* _tail;
 	unsigned _size;

 public:
	Stack();

	bool empty();
	unsigned size();
	void push(T);
	void pop();
	T top();
};

template <typename T>
Stack<T>::Stack() : _tail(nullptr), _size(0) {}

template <typename T>
bool Stack<T>::empty() {
	return this->_size == 0;
}

template <typename T>
unsigned Stack<T>::size() {
	return this->_size;
}

template <typename T>
void Stack<T>::push(T val) {
	node<T>* new_node = new node<T>(val);
	if (!this->_tail) {
		this->_tail = new_node;
	} else {
		this->_tail->next = new_node;
		new_node->prev = this->_tail;
		this->_tail = new_node;
	}
	this->_size++;
}

template <typename T>
void Stack<T>::pop() {
	if (this->_tail) {
		node<T>* new_tail = this->_tail->prev;
		
		delete this->_tail;
		this->_tail = new_tail;
		if (this->_tail) {
			this->_tail->next = nullptr;
		}
		this->_size--;
	} else {
		throw std::out_of_range("Called pop on an empty stack.");
	}
}

template <typename T>
T Stack<T>::top() {
	return this->_tail->data;
}

#endif