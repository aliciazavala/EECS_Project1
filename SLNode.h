#ifndef SLNODE_H
#define SLNODE_H

template <typename T>
class SLNode // A node in a singly linked list
{
private:
	T item;
	SLNode* next; // we can only go "forward" along our chain
public:
	SLNode(T anItem) : item(anItem), next(nullptr) {}
	SLNode(T anItem, SLNode* nextSLNode) : item(anItem), next(nextSLNode) {}
	T getItem() const { return item; }
	SLNode* getNext() const { return next; }
	void setItem(T newItem) { item = newItem; }
	void setNext(SLNode* nextSLNode) { next = nextSLNode; }
};

#endif
