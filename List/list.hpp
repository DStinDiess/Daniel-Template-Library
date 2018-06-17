#include <stdexcept>

#ifndef __DSD_LIST__
#define __DSD_LIST__

template <typename T>
struct node {
	T data;
	node* next;
	node* prev;

	node() : data(0), next(nullptr), prev(nullptr) {}
	node(T val) : data(val), next(nullptr), prev(nullptr) {}
};


template <typename T>
class List {
 private:
 	node<T>* _head;
	node<T>* _tail;
	int _size;

 public:
	List();
	List(T);

	bool empty();
	unsigned size();
	T front();
	T back();
	void push_front(T);
	void pop_front();
	void push_back(T);
	void pop_back();
};

template <typename T>
List<T>::List() : _head(nullptr), _tail(nullptr), _size(0) {
}

template <typename T>
bool List<T>::empty() {
	return this->_size == 0;
}

template <typename T>
unsigned List<T>::size() {
	return this->_size;
}

template <typename T>
T List<T>::front() {
	return this->_head->data;
}

template <typename T>
T List<T>::back() {
	return this->_tail->data;
}

template <typename T>
void List<T>::push_front(T val) {
	node<T>* new_node = new node<T>(val);

	if (!this->_head) {
		this->_head = new_node;
		this->_tail = new_node;
	} else {
		new_node->next = this->_head;
		this->_head->prev = new_node;
		this->_head = new_node;
	}
	this->_size++;
}

template <typename T>
void List<T>::pop_front() {
	if (this->_head) {
		node<T>* new_front = this->_head->next;

		delete this->_head;
		this->_head = new_front;
		if (this->_head) {
			this->_head->prev = nullptr;
		}
		
		this->_size--;
	} else {
		throw std::out_of_range("Called pop_front() on an empty list");
	}
}

template <typename T>
void List<T>::push_back(T val) {
	node<T>* new_node = new node<T>(val);

	if (!this->_tail) {
		this->_head = new_node;
		this->_tail = new_node;
	} else {
		new_node->prev = this->_tail;
		this->_tail->next = new_node;
		this->_tail = new_node;
	}
	this->_size++;
}

template <typename T>
void List<T>::pop_back() {
	if (this->_tail) {
		node<T>* new_tail = this->_tail->prev;

		delete this->_tail;
		this->_tail = new_tail;
		if (this->_tail) {
			this->_tail->next = nullptr;
		}

		this->_size--;
	} else {
		throw std::out_of_range("Called pop_back() on an empty list");
	}
}

#endif
