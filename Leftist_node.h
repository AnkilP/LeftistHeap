
/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID: a293pate@edu.uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission: Fall 2018
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

#ifndef LEFTIST_NODE_H
#define LEFTIST_NODE_H

#include <algorithm>
#include <iostream>
// You may use std::swap and std::min
#ifndef nullptr
#define nullptr 0
#endif

template <typename Type>
class Leftist_node {
	private:
		Type element;
		Leftist_node *left_tree;
		Leftist_node *right_tree;
		int heap_null_path_length;

	public:
		Leftist_node( Type const & );

		Type retrieve() const;
		bool empty() const;
		Leftist_node *left() const;
		Leftist_node *right() const;
		int count( Type const & ) const;
		int null_path_length() const;

	void push(Leftist_node *, Leftist_node *&);
		void clear();
};

template <typename Type>
Leftist_node<Type>::Leftist_node( Type const &obj ):
element( obj ),
left_tree( nullptr ),
right_tree( nullptr ),
heap_null_path_length( 0 ) {
	// does nothing
}

// You may need this

template <typename Type>
bool Leftist_node<Type>::empty() const {
	return ( this == nullptr );
}

template<typename Type>
Type Leftist_node<Type>::retrieve() const {
    if(!empty()){
        return this->element;
    }
}

template<typename Type>
Leftist_node<Type> *Leftist_node<Type>::left() const {
	return this->left_tree;
}

template<typename Type>
Leftist_node<Type> *Leftist_node<Type>::right() const {
	return this->right_tree;
}

template<typename Type>
int Leftist_node<Type>::count(const Type & obj) const {
	if(this->empty()){
	    return 0;
	}
	int counter = 0;
	if(this->left() != nullptr){ //look in left subtree
	    counter += this->left_tree->count(obj);
	}
    if(this->right() != nullptr){ //look in right subtree
        counter += this->right_tree->count(obj);
    }
    if(this->retrieve() == obj){
        return 1;
    }
    return counter;
}

template<typename Type>
int Leftist_node<Type>::null_path_length() const {
	if (this != nullptr) {
		return 1 + std::min(this->left_tree->null_path_length(),this->right_tree->null_path_length());
	} else {
		return -1;
	}
}

template<typename Type>
void Leftist_node<Type>::push(Leftist_node<Type> *new_heap, Leftist_node<Type> *&ptr_to_this) {
	if (new_heap == nullptr) {
		return;
	}
	if (ptr_to_this->empty()) {
		ptr_to_this = new_heap;
		return;
	}
	if (ptr_to_this->retrieve() <= new_heap->retrieve()) {
        ptr_to_this->right_tree->push(new_heap, ptr_to_this->right_tree);
        ptr_to_this->heap_null_path_length = ptr_to_this->null_path_length();
        //std::cout << heap_null_path_length << std::endl;

        if (ptr_to_this->left()->null_path_length() < ptr_to_this->right()->null_path_length()) {
            //           left                       <              right
            Leftist_node<Type> *temp_node = ptr_to_this->left_tree;
            ptr_to_this->left_tree = ptr_to_this->right_tree;
            ptr_to_this->right_tree = temp_node;
        }
    }
    else{
        ptr_to_this = new_heap;
        ptr_to_this->push(this, ptr_to_this);
    }
}

template<typename Type>
void Leftist_node<Type>::clear() {
	if (this->empty()) {
		return;
	}
	//can I make this recursive?
    if(this->left() != nullptr){ //look in left subtree
        this->left_tree->clear();
    }
    if(this->right() != nullptr){ //look in right subtree
        this->right_tree->clear();
    }
    delete this;

}


#endif
