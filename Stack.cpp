template<typename ItemType>
Stack<ItemType>::Stack() //stack constructor sets m_top to nullptr
{
	m_top = nullptr;
}


template<typename ItemType>
Stack<ItemType>::Stack(const Stack<ItemType>& original) //copy constructor of stack
{
	m_top = nullptr;
	SLNode<ItemType>* nodePtr = original.m_top;
	Stack<ItemType> transferStack;
	while(nodePtr != nullptr)
	{
		transferStack.push(nodePtr->getItem()); //moves items from original stack to copy stack
		nodePtr = nodePtr->getNext();
	}
	while(transferStack.m_top != nullptr)
	{
		push(transferStack.peek()); //puts items in copy stack in correct order
		transferStack.pop();
	}
}


template<typename ItemType>
Stack<ItemType>::~Stack()
{
	while(!isEmpty())
	{
		pop(); //deletes all nodes in stack
	}
}

template<typename ItemType>
bool Stack<ItemType>::isEmpty() const //checks to see if there are items in stack or not
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
		throw(std::runtime_error("Out of memory!"));
	}
	else
	{
		temp->setNext(m_top); //adds a new item to stack
		m_top = temp;
	}
}

template<typename ItemType>
void Stack<ItemType>::pop()
{
	if(!isEmpty())
	{
		SLNode<ItemType>* temp = m_top; //removes top item from stack
		m_top = temp->getNext();
		delete temp;
	}
	else
	{
		throw(std::runtime_error("No items to remove!"));
	}
}

template<typename ItemType>
ItemType Stack<ItemType>::peek() const
{
    if(isEmpty())
	{
		throw(std::runtime_error("No items to peek in stack!"));
	}
	return m_top->getItem(); //shows top entry in stack
}
