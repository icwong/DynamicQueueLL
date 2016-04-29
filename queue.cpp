/*File: queue.cpp
Implementation of functions for basic simple array-based implementation of a queue.
Dynamic version.

*/

#include "queue.h"// contains the declarations of the variables and functions.
#include <string>
#include <iostream>

using namespace std; 


// Default constructor
Queue::Queue(){
	front_p = NULL;
	back_p = NULL;
	current_size = 0;
}

// Copy constructor.
Queue::Queue(const Queue& q){
	front_p = NULL;
	back_p = NULL;
	node * curr = q.front_p;
	while (curr != NULL){
		int a = curr -> data;
		enqueue(a);
		curr = curr->next;
	}
}	


// Destructor.
Queue::~Queue(){
	while (front_p != NULL && back_p != NULL){
		node * next = front_p->next;
		delete front_p;
		front_p = next;
	}
}



/**************************************************************************/
// Operations
void Queue::enqueue(int item){ // Enqueues <item>.
	node * temp;
	temp = new node( item, NULL ); 
		
	if(front_p == NULL){
		front_p = temp;
	}

	else{
		back_p->next = temp;
	}

	back_p = temp;
    current_size++;
}

int Queue::dequeue(){ // Dequeues the front item.
	if (front_p == NULL && back_p == NULL){
		return false;
	}
	node * old_front = front_p;
	int temp = old_front->data;
	front_p = front_p->next;
	delete old_front;
	current_size--;
	return temp;
}

int Queue::front(){ // Returns the front item without dequeuing it.
	if (front_p == NULL && back_p == NULL){
		return false;
	}
	return front_p->data;
}

bool Queue::empty(){ // Returns true iff the queue contains no items.
	if(front_p == NULL){
		return true;
	}
	return false;
}

int Queue::size(){ // Returns the current number of items in the queue.
	return current_size;
}

int Queue::makeUnique(int item){ // If <item> occurs in the queue more 
	node* current = front_p;
	node* previous = NULL;
	int Num = 0;
	bool IsFirst = true;
	while (current != NULL){
		if (current->data == item && IsFirst == true){
			IsFirst = false;
			previous = current;
			current = current->next;
		}

		else if(current->data == item && IsFirst == false){
			node* temp = current;
			current = current->next;
			previous->next = current;
			delete temp;
			Num++;
			current_size--;
		}

		else{
			previous = current;
			current = current->next;
		}
	}
	return Num;
}
