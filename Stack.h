#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"
#include "SLNode.h"

template<class ItemType>
class Stack : public StackInterface<ItemType>
{
	public:
	Stack();
	Stack(const Stack<ItemType>& original);
	~Stack();

	/**
	@pre none
	@post all member variable will remain constant
	@return returns true if there is no items in the Stack, false otherwise*/
	bool isEmpty() const;

	/**
	@pre none
	@post adds and item to the Stack
	@param newEntry is the item to be added passed in by reference
	@throw throws an exception if there is no memory available for allocation in the heap*/
	void push(const ItemType& newEntry);

	/**
	@pre the Stack must have items 
	@post the SLNode which m_top points to is removed
	@throw throws an exception if there are no items in the Stack*/
	void pop();

	/**
	@pre the Stack must have items
	@post all SLNodes remain unchanged
	@throw throws an exception if there are no items in the Stack
	@return returns the item at the top of the Stack*/
	ItemType peek() const;

	private:
	SLNode<ItemType>* m_top;
};

#include "Stack.cpp"
#endif
