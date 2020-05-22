/*
 * List.h
 *
 *  Created on: Mar 12, 2020
 *      Author: Einstein Essibu (se27)
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cassert>
using namespace std;

template <class Item>
class List {
public:
	List();
	List(const List<Item>& original);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(Item it);
	void prepend(Item it);
	void insert(Item it, int index);
	List<Item>& operator=(const List<Item>& l2);
	bool operator==(const List<Item>& l2);
	bool operator!=(const List<Item>& l2);
	void readFrom(istream& cin);
	void writeTo(const string& fileName);
	void writeTo(ostream& out, char separator = ' ') const;
	void readFrom(const string& fileName);
	int getIndexOf(const Item& it);
	Item remove(int index);

	bool insertAfter(const Item& otherPersonsName, const Item& yourName);
	bool insertBefore(const Item& otherPersonsName, const Item& yourName);

	~List();

private:
	unsigned mySize;
	struct Node {
		Node();
		Node(Item it, Node* next);
		Item myItem;
		Node* myNext;
		~Node();
	};
	Node* myFirst;
	Node* myLast;
	friend class ListTester;
};

// Default constructor for List object
template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

// Default constructor for Node object
template <class Item>
List<Item>::Node::Node() {
	myItem = 0;
	myNext = NULL;
}

// Explicit constructor for Node object
template <class Item>
List<Item>::Node::Node(Item it, Node* next) {
	myItem = it;
	myNext = next;
}

// Getter for size of List object
template <class Item>
unsigned List<Item>::getSize() const {
	return mySize;
}

// Getter for List object. "getFirst()"
template <class Item>
Item List<Item>::getFirst() const {
	if (mySize < 0 || myFirst == NULL) {
		throw underflow_error("List is empty so cannot get values");
	} else {
		return myFirst->myItem;
	}
}

// Getter for List object. "getLast()"
template <class Item>
Item List<Item>::getLast() const {
	if (mySize < 0 || myLast == NULL) {
		throw underflow_error("List is empty so cannot get values");
	} else {
		return myLast->myItem;
	}
}

// Appends node with value to the list
template <class Item>
void List<Item>::append(Item it) {
	List::Node* newNodePtr = new List::Node(it, NULL);
	if (mySize == 0) {
		myFirst = newNodePtr;
	} else {
		myLast->myNext = newNodePtr;
	}
	myLast = newNodePtr;
	mySize++;
}

// Prepends node with value to beginning of list
template <class Item>
void List<Item>::prepend(Item it) {
	List::Node* newNodePtr = new List::Node(it, NULL);
	if (mySize == 0) {
		myLast = newNodePtr;
	} else {
		newNodePtr->myNext = myFirst;
	}
	myFirst = newNodePtr;
	mySize++;
}

//
template <class Item>
void List<Item>::insert(Item it, int index) {
	if (index <= 0 || mySize == 0) {
		prepend(it);
	} else if (index >= mySize) {
		append(it);
	} else {
		Node* tempPtr = myFirst;
		for (unsigned i = 0; i < index-1; ++i) {
			tempPtr = tempPtr->myNext;
		}
		Node* newNodePtr = new List<Item>::Node(it, tempPtr->myNext);
		tempPtr->myNext = newNodePtr;
		mySize++;
	}

}

// Copy constructor
template <class Item>
List<Item>::List(const List<Item>& original) {
	myFirst = myLast = NULL;
	mySize = 0;
	if (original.mySize > 0) {
		Node* oPtr = original.myFirst;
		while (oPtr != NULL) {
			append(oPtr->myItem);
			oPtr = oPtr->myNext;
		}
	}
}

// Assignment operator
template <class Item>
List<Item>& List<Item>::operator=(const List<Item>& original) {
	if (this != &original) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		Node* nPtr = original.myFirst;
		while (nPtr != NULL) {
			append(nPtr->myItem);
			nPtr = nPtr->myNext;
		}
	}
	return *this;
}

// Equality operator
template <class Item>
bool List<Item>::operator==(const List<Item>& l2) {
	if (mySize != l2.mySize) {
		return false;
	} else {
		Node* Ptr1 = myFirst;
		Node* Ptr2 = l2.myFirst;
		while (Ptr1 != NULL) {
			if (Ptr1->myItem != Ptr2->myItem) {
				return false;
			}
			Ptr2 = Ptr2->myNext;
			Ptr1 = Ptr1->myNext;
		}
		return true;
	}
}

// Inequality operator
template <class Item>
bool List<Item>::operator!=(const List& l2) {
	if (mySize == l2.mySize) {
		Node * Ptr2 = l2.myFirst;
		for (Node * Ptr1 = myFirst; Ptr1; Ptr1 = Ptr1->myNext) {
			if (Ptr1->myItem != Ptr2->myItem) {
				return true;
			}
			Ptr2 = Ptr2->myNext;
		}
		return false;
	}
	return true;
}

// Reads line from istream and creates list
template <class Item>
void List<Item>::readFrom(istream& cin) {
	string line;
	getline(cin, line);
	stringstream streamLine(line);
	Item tempVal;
	while (streamLine >> tempVal) {
		append(tempVal);
	}
}

// Writes list values to a file with each value on a new line
template <class Item>
void List<Item>::writeTo(const string& fileName) {
	ofstream fout(fileName.c_str());
	Node* myPtr = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		fout << myPtr->myItem << endl;
		myPtr = myPtr->myNext;
	}
	fout.close();
}

// writeTo ostream. Writes the items of list into a file.
template <class Item>
void List<Item>::writeTo(ostream& out, char separator) const {
	for (Node * temp = myFirst; temp; temp = temp->myNext) {
		if (temp->myNext == nullptr)
			out << temp->myItem;
		else {out << temp->myItem << separator;}
	}
}

// readFrom string. Reads list from file.
template <class Item>
void List<Item>::readFrom(const string& fileName) {
	delete myFirst;
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	Item num;
	while (true) {
		if (fin >> num) {
			append(num);
		} else {
			break;
		}
	}
	fin.close();
}

// getIndexOf. Finds the index of item in list.
template <class Item>
int List<Item>::getIndexOf(const Item& it) {
	unsigned i = 0;
	for (Node * nPtr = myFirst; nPtr; nPtr = nPtr->myNext) {
		if (nPtr->myItem == it) {
			return i;
		}
		i++;
	}
	return -1;
}

//
template<class Item>

Item List<Item>::remove(int index) {
	Node * Ptr = myFirst;
	Item value;
	if(mySize == 0){
		// removing from empty list
		throw underflow_error("Nothing to remove");
	}
	else if(mySize ==1){
		// removing last item
		value = myFirst->myItem;
		myFirst->myNext = NULL;
		myFirst = myLast = NULL;
	} else if(index <= 0){
		// lowest index
		value = myFirst->myItem;
		myFirst = myFirst->myNext;
		Ptr->myNext = NULL;
	}else if (index >= int(mySize-1)){
		// highest index
		for(unsigned i = 0; i < mySize; i++){
			if(i == mySize-1){
				value = myLast->myItem;
				Ptr->myNext = NULL;
				myLast->myNext = NULL;
				delete myLast;
			}
			Ptr = Ptr->myNext;
		}
	}
	else {
		// middle index
		Node * prevPtr = myFirst;
		for (unsigned i = 0; i < mySize; i++) {
			if (int(i) == index) {
				value = Ptr->myItem;
				prevPtr->myNext = Ptr->myNext;
				Ptr->myNext = NULL;
				break;
			}
			prevPtr = Ptr;
			Ptr = Ptr->myNext;
		}
	}
	delete Ptr;
	mySize -=1;
	return value;
}

// Insert Before function
template <class Item>
bool List<Item>::insertBefore(const Item& otherPersonsName, const Item& yourName) {
	if (mySize == 0) {
		return false;
	}
	unsigned index = 0;
	Node* tempPtrPrev;
	for (Node* tempPtr = myFirst; tempPtr; tempPtr = tempPtr->myNext) {
		if (tempPtr->myItem == otherPersonsName) {
			if (index == 0) {
				prepend(yourName);
			} else if (index >= mySize) {
				append(yourName);
			} else {
				Node* newNodePtr = new List<Item>::Node(yourName, tempPtr);
				tempPtrPrev->myNext = newNodePtr;
				mySize++;
			}
			return true;
		}
		tempPtrPrev = tempPtr;
		index++;
	}
	return false;
}

// Insert After function
template <class Item>
bool List<Item>::insertAfter(const Item& otherPersonsName, const Item& yourName) {
	if (mySize == 0) {
		return false;
	}
	unsigned index = 0;
	for (Node* tempPtr = myFirst; tempPtr; tempPtr = tempPtr->myNext) {
		if (tempPtr->myItem == otherPersonsName) {
			if ( ++index == mySize ) {
				append(yourName);
			} else {
				Node* newNodePtr = new List<Item>::Node(yourName, tempPtr->myNext);
				tempPtr->myNext = newNodePtr;
				mySize++;
			}
			return true;
		}
	}
	return false;
}

template <class Item>
ostream& operator<<(ostream& out, const List<Item>& l) {
			l.writeTo(out, "=");
			return out;
		}

// Destructor for List objects
template <class Item>
List<Item>::~List() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

// Destructor for Node Objects
template <class Item>
List<Item>::Node::~Node() {
	delete myNext;
}

#endif /* LIST_H_ */
