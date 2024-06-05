#include <iostream>
#include <cassert>
#include <string>

template<typename T>
struct LinkedNode
{
	T data;
	LinkedNode* next;
	LinkedNode* prev;
};

template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& rhs);
	LinkedList& operator=(const LinkedList& rhs);
	bool isEmpty();
	LinkedNode* getFirst();
	LinkedNode* getLast();
	void insertFirst(T data);
	void insertLast(T data);
	void insertAfter(T tKey, T tData);
	void removeFirst();
	void removeLast();
	void remove(T removalCandidate);
	void destroy();
private:
	LinkedNode* mFirst;
	LinkedNode* mLast;
};

// Constructor
template<typename T>
LinkedList<T>::LinkedList()
{
	mFirst = nullptr;
	mLast = nullptr;
}
// Destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
	destroy();
}

// Copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& rhs)
{
	// Implement your copy constructor logic here
	// Make sure to deep copy the linked list
	this->mFirst = rhs.mFirst;
	this->mLast = rhs.mLast;
	
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs)
{
	if (this != &rhs)
	{
		this->mFirst = rhs.mFirst;
		this->mLast = rhs.mLast;		
	}
	return *this;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
	return mFirst == nullptr;
}

// Get the first node
template<typename T>
LinkedNode<T>* LinkedList<T>::getFirst()
{
	return mFirst;
}

// Get the last node
template<typename T>
LinkedNode<T>* LinkedList<T>::getLast()
{
	return mLast;
}


// Insert a new node at the beginning
template<typename T>
void LinkedList<T>::insertFirst(T data)
{
	LinkedNode<T>* newNode = new LinkedNode<T>;
	newNode->data = data;
	newNode->next = mFirst;
	newNode->prev = nullptr;

	if (mFirst)
		mFirst->prev = newNode;
	else
		mLast = newNode;

	mFirst = newNode;
}

// Insert a new node at the end
template<typename T>
void LinkedList<T>::insertLast(T data)
{

	LinkedNode<T>* newNode = new LinkedNode<T>;
	newNode->data = data;
	newNode->next = nullptr;
	newNode->prev = mLast;

	if (mLast)
		mLast->next = newNode;
	else
		mFirst = newNode;

	mLast = newNode;


}

// Insert a new node after a specific key
template<typename T>
void LinkedList<T>::insertAfter(T tKey, T tData)
{
	// Implement your insertAfter logic here
	LinkedNode* newNode = new LinkedNode(tData); // Create a new node with the given data

	if (!mFirst) // If the list is empty, set the new node as the first node
	{
		mFirst = newNode;
		mLast = newNode;
	}
	else
	{
		LinkedNode* current = mFirst;
		while (current)
		{
			if (current->getData() == tKey) // Find the node with data tKey
			{
				newNode->setNext(current->getNext()); // Set the new node's next pointer
				current->setNext(newNode); // Update the current node's next pointer
				if (current == mLast) // If the current node is the last node, update mLast
					mLast = newNode;
				break;
			}
			current = current->getNext();
		}
	}

}


// Remove the first node
template<typename T>
void LinkedList<T>::removeFirst()
{
	// Implement your removeFirst logic here
	if (!mFirst) // If the list is empty, nothing to remove
		return;

	LinkedNode* temp = mFirst; // Store the first node
	mFirst = mFirst->getNext(); // Update mFirst to point to the next node

	delete temp; // Delete the original first node
}

// Remove the last node
template<typename T>
void LinkedList<T>::removeLast()
{
	if (!mFirst) // If the list is empty, nothing to remove
		return;

	if (!mFirst->getNext()) // If there's only one node, delete it
	{
		delete mFirst;
		mFirst = nullptr;
		mLast = nullptr;
		return;
	}

	LinkedNode* secondLast = mFirst;
	while (secondLast->getNext()->getNext())
		secondLast = secondLast->getNext();

	delete mLast; // Delete the last node
	mLast = secondLast; // Update mLast to point to the second last node
	mLast->setNext(nullptr); // Set the next pointer of the new last node to null
}


// Remove a specific node
template<typename T>
void LinkedList<T>::remove(T removalCandidate)
{
	// Implement your remove logic here
	if (!mFirst) // If the list is empty, nothing to remove
		return;

	if (mFirst->getData() == removalCandidate) // If the first node matches the removalCandidate
	{
		LinkedNode* temp = mFirst;
		mFirst = mFirst->getNext();
		delete temp;
		if (!mFirst) // If the list becomes empty after removal
			mLast = nullptr;
		return;
	}

	LinkedNode* current = mFirst;
	while (current->getNext())
	{
		if (current->getNext()->getData() == removalCandidate)
		{
			LinkedNode* temp = current->getNext();
			current->setNext(temp->getNext());
			delete temp;
			if (!current->getNext()) // If the last node was removed
				mLast = current;
			return;
		}
		current = current->getNext();
	}
}

// Destroy the entire linked list
template<typename T>
void LinkedList<T>::destroy()
{
	while (mFirst)
	{
		LinkedNode<T>* temp = mFirst;
		mFirst = mFirst->next;
		delete temp;
	}
	mLast = nullptr;
}


using namespace std;


int main()
{
	

	return 0;
    
}