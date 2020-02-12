template<typename ItemType>
Stack<ItemType>::Stack()
{
	m_top = nullptr;
}


template<typename ItemType>
Stack<ItemType>::Stack(const Stack<ItemType>& original)
{
	m_top = nullptr;
	SLNode<ItemType>* nodePtr = original.m_top;
	Stack<ItemType> transferStack;
	while(nodePtr != nullptr)
	{
		transferStack.push(nodePtr->getItem());
		nodePtr = nodePtr->getNext();
	}
	while(transferStack.m_top != nullptr)
	{
		push(transferStack.peek());
		transferStack.pop();
	}
}


template<typename ItemType>
Stack<ItemType>::~Stack()
{
	while(!isEmpty())
	{
		pop();
	}
}

template<typename ItemType>
bool Stack<ItemType>::isEmpty() const
{
	if(m_top == nullptr)
	{
		return true;
	}
	return false;
}

template<typename ItemType>
void Stack<ItemType>::push(const ItemType& newEntry)
{
	SLNode<ItemType>* temp = new SLNode<ItemType>(newEntry);
	if(temp == nullptr)//memory check
	{
		throw(PrecondViolatedExcep("Out of memory!"));
	}
	else
	{
		temp->setNext(m_top);
		m_top = temp;
	}
}

template<typename ItemType>
void Stack<ItemType>::pop()
{
	if(!isEmpty())
	{
		SLNode<ItemType>* temp = m_top;
		m_top = temp->getNext();
		delete temp;
	}
	else
	{
		throw(PrecondViolatedExcep("No items to remove!"));
	}
}

template<typename ItemType>
ItemType Stack<ItemType>::peek() const
{
    if(isEmpty())
	{
		throw(PrecondViolatedExcep("No items to peek in stack!"));
	}
	return m_top->getItem();
}
