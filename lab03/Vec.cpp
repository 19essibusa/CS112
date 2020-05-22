/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "Vec.h"
#include <fstream>

Vec::Vec()
{
	mySize = 0;
	myArray = NULL;
}

Vec::Vec(unsigned size)
{
	mySize = size;

	if (mySize > 0)
	{
		myArray = new Item[size]();
	}

	else
	{
		myArray = NULL;
	}
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	myArray = new Item[mySize]();


	if (original.mySize > 0)
	{

		for (unsigned i = 0; i < mySize; ++i)
		{
			myArray[i] = original.myArray[i];
		}
	}


	else
	{
		mySize = 0;
		myArray = NULL;
	}


}

Vec::~Vec()
{
	mySize = 0;
	delete [] myArray;
	myArray = NULL;
}

Vec& Vec::operator=(const Vec& original)
{

	if(myArray == original.myArray)
	{
		return*this;
	}

	else if(original.mySize == 0)
	{
		mySize = 0;
		delete [] myArray;
		myArray = NULL;

		return*this;
	}

	else
	{
		mySize = original.mySize;
		delete [] myArray;
		myArray = new Item[mySize];

		for (unsigned i = 0; i < mySize; ++i)
		{
			myArray[i] = original.myArray[i];
		}
		return*this;
	}




}


unsigned Vec::getSize() const
{
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it)
{
	if (index >= mySize || index < 0 || mySize == 0) {
		throw range_error("The range cannot be found");
	} else {
		myArray[index] = it;
	}
}

Item Vec::getItem(unsigned index) const
{

	if (index >= mySize || index < 0 || mySize == 0)
	{
		throw range_error("The range is invalid");
	}
	else
	{
		return myArray[index];
	}

}
void Vec::setSize(unsigned newSize)
{
	if (mySize == 0) {
		mySize = newSize;
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = 0;
		}
	} else if (newSize == 0) {
		mySize = 0;
		delete [] myArray;
		myArray = NULL;
	} else  if (newSize == mySize) {

	} else {
		Item* temp = myArray;
		myArray = new Item[newSize];
		unsigned oldSize = mySize;
		mySize = newSize;

		if (oldSize < newSize) {
			for (unsigned i = 0; i < oldSize; ++i) {
				myArray[i] = temp[i];
			}
			for (unsigned i = oldSize; i < newSize; ++i) {
				myArray[i] = 0;
			}
		} else {
			for (unsigned i = 0; i < newSize; ++i) {
				myArray[i] = temp[i];
			}
		}
		delete [] temp;
	}
}
bool Vec::operator==(const Vec& v2) const
		{
	if(mySize!=v2.mySize)
	{
		return false;
	}
	else
	{
		for (unsigned i = 0; i<mySize; i++)
		{
			if (myArray[i] != v2.myArray[i])
			{
				return false;
			}
		}
		return true;
	}
		}

void Vec::writeTo(ostream& out) const
{
	for(unsigned i=0; i<mySize; i++)
	{
		out << myArray[i] << endl;
	}
}

void Vec::readFrom(istream& in)
{
	for(unsigned i=0; i<mySize; i++)
		{
			in >> myArray[i];
		}
}

Item& Vec::operator[](unsigned index) const
{
	if (index >= mySize)
	{
		throw range_error("The range cannot be found");
	}

	else
	{
		return myArray[index];
	}

}

bool Vec::operator!=(const Vec& v2)
{
	if (v2.mySize!=mySize)
	{
		return true;
	}

	else
	{
		for (unsigned i = 0; i<mySize; i++)
				{
					if (myArray[i] != v2.myArray[i])
					{
						return true;
					}
				}
				return false;
	}

}
void Vec::readFrom(const string& filename) {
    ifstream fin( filename.c_str() );
    fin >> mySize;

    delete [] myArray;
    myArray = new Item['mySize'];
    //log out of your computer
    for (unsigned i = 0; i < mySize; ++i) {
    	fin >> myArray[i];
    }
	fin.close();

}

/* operator+() adds vector values together
 * parameter: Vec & v2
 * precondition: two vecs
 * postcondition: v3 contains values from v1 and v2.
 */
Vec Vec::operator+(Vec& v2) {

	if (mySize != v2.mySize)
	{
		throw invalid_argument("The objects needs to have equal sizes to add");
	}
	else {
		Vec v3(mySize);//// Equality method for Vec class
		for (unsigned i= 0; i < mySize; ++i) {
			v3.myArray[i] = myArray[i] + v2.myArray[i];
		}
		return v3;
	}
}

//Subtraction
Vec Vec::operator-(const Vec& v2){

	if (mySize != v2.mySize){
		throw invalid_argument("Invalid Argument");
	}
	else {
		Vec v3(mySize);
		for (unsigned i = 0; i < mySize; i++){
			v3.myArray[i] = myArray[i] - v2.myArray[i];
		}
		return v3;
	}

}


//writeTo
void Vec::writeTo(const string& fileName){
	ofstream fout (fileName.c_str());
	//	assert(fout.is_open());
	fout << mySize << '\n';
	for (unsigned i = 0; i < mySize; i++){
		fout << myArray[i] << '\n';
	}
	fout.close();
}

//Dot Product
Item Vec::operator*(const Vec& v2){
	Item product = 0;
	if (mySize != v2.mySize){
		throw invalid_argument("vectors have different sizes");
	}else if (v2.mySize == 0){
		return product;
	}
	for (unsigned i = 0; i < mySize; i++){
		product += myArray[i] * v2.myArray[i];
	}
	return product;
}



