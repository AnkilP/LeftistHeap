
/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  a293pate@edu.uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  Fall 2019
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Leftist_node.h"
#include <ostream>
#include "Exception.h"

template <typename Type>
class Leftist_heap {
	private:
		Leftist_node<Type> *root_node;
		int heap_size;

	public:
		Leftist_heap();
		~Leftist_heap();

		void swap( Leftist_heap &heap );
		

		bool empty() const;
		int size() const;
		int null_path_length() const;
		Type top() const;
		int count( Type const & ) const;

		void push( Type const & );
		Type pop();
		void clear();

	// Friends

	template <typename T>
	friend std::ostream &operator<<( std::ostream &, Leftist_heap<T> const & );
};

// some sample functions are given

template <typename Type>
Leftist_heap<Type>::Leftist_heap():
root_node( nullptr ),
heap_size( 0 ) {
	// does nothing
}

template <typename Type>
Leftist_heap<Type>::~Leftist_heap() {
	clear();  // might as well use it...
}

template <typename Type>
void Leftist_heap<Type>::swap( Leftist_heap<Type> &heap ) {
	std::swap( root_node, heap.root_node );
	std::swap( heap_size, heap.heap_size );
}

template<typename Type>
bool Leftist_heap<Type>::empty() const {
	if (this->heap_size <= 0) {
		return true;
	} else {
		return false;
	}
}

template<typename Type>
int Leftist_heap<Type>::size() const {
	return this->heap_size;
}

template<typename Type>
int Leftist_heap<Type>::null_path_length() const {
	if (this->empty()) {
		return -1;
	}
	return root_node->null_path_length();
}

template<typename Type>
Type Leftist_heap<Type>::top() const {
	if (this->empty()) {
		throw underflow();
	}
	return root_node->retrieve();
}

template<typename Type>
int Leftist_heap<Type>::count(const Type & obj) const {
	if(this->empty()){
		return 0;
	}
	return this->root_node->count(obj);
}

template<typename Type>
void Leftist_heap<Type>::push(const Type & obj) {
	Leftist_node<Type> * n = new Leftist_node<Type>(obj);
	this->root_node->push(n, root_node);
	this->heap_size = this->heap_size + 1;
}

template<typename Type>
Type Leftist_heap<Type>::pop() {
	if(empty()){
		throw underflow();
	}

	Leftist_node<Type> * temp_left = this->root_node->left();
	Type value = root_node->retrieve();
	Leftist_node<Type> * temp_right = this->root_node->right();

	delete this->root_node;
	this->root_node = temp_left;
	this->root_node->push(temp_right, this->root_node);
	this->heap_size = this->heap_size -1;
	return value;
}

template<typename Type>
void Leftist_heap<Type>::clear() {
	this->root_node->clear();
	this->root_node = nullptr;
	this->heap_size = 0;
}
// You can modify this function however you want:  it will not be tested

template <typename T>
std::ostream &operator<<( std::ostream &out, Leftist_heap<T> const &heap ) {
	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
