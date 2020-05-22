/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: Einstein Essibu
 * Date:
 */
//


#include "ArrayQueue.h"
#include <cstring>      // memcpy()
using namespace std;

/* copy constructor
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}

/* destructor
 * Postcondition: my dynamic array has been deallocated.
 */
ArrayQueue::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
bool ArrayQueue::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
bool ArrayQueue::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
unsigned ArrayQueue::getSize() const {
	return mySize;
}

ArrayQueue::ArrayQueue(int capacity){
	if (capacity==0){
		throw EmptyQueueException("ArrayQueue::ArrayQueue(int capacity)");
	}

	myCapacity = capacity;
	mySize = 0;
	myFirstIndex = 0;
	myLastIndex = capacity-1;
	myArrayPtr = new Item[capacity];
}

Item ArrayQueue::getLast() const{
	if( isEmpty()){
		throw EmptyQueueException("ArrayQueue::getLast()");
	}
	return myArrayPtr[myLastIndex];
}

Item ArrayQueue::getFirst() const{
	if( isEmpty()){
		throw EmptyQueueException("ArrayQueue::getLast()");
	}
	return myArrayPtr[myFirstIndex];
}

void ArrayQueue::append(const Item& it){
	if (isFull()){
		throw FullQueueException("append(const Item& it)");
	}
	myLastIndex = (myLastIndex+1)% myCapacity;
	myArrayPtr[myLastIndex] = it;
	mySize++;
}

Item ArrayQueue::remove(){
	if (isEmpty()){
		throw EmptyQueueException("ArrayQueue::remove()");
	}
	Item result = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex+1) % myCapacity;
	mySize--;
	return result;

}

