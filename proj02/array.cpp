/* array.cpp defines "C style" array operations
 * Name: Einstein Essibu(se27)
 * Date: 18 Feb, 2020
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "array.h"
#include <fstream>


void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}


void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}


double average(double *a, unsigned size) {
	double total = 0;
	for (unsigned i = 0; i < size; i++) {
		total += *a;
		a++;
	}

	total = total/size;
	return total;
}


// The location of an array is taken and is repeated when it is summing
//
double sum(double *a, unsigned size)
{
	double sum = 0;
	for (unsigned i = 0; i < size; i++) {
		sum += *a;
		a++;

		cout << *a << '\t';
	}
	return sum;
}

// An array is a created utitlizing istream and while also putting them at the location *a
//points to and creates an array of size "size"
//
void read(istream& in, double *a, unsigned size)
{
	int store;
	for (unsigned i = 0; i < size; i++) {
		in >> store;
		a[i] = store;
	}
}

//The function reads the file and puts in a an array. It then creates an array at the location of a

void fill(const string& fileName, double *&a, unsigned &numValues)
{
	ifstream fin;
	fin.open(fileName);
	fin >> numValues;

	delete [] a;
	a = new double[numValues];

	int store;
	for (unsigned i = 0; i < numValues; i++) {
		fin >> store;
		a[i] = store;
	}
	fin.close();



}

// It adds zero to an array on the end if newSize is bigger and truncates is newSize is smaller

void resize(double *&a, unsigned oldSize, unsigned newSize) {

	double* old = new double[oldSize];

	for(unsigned i = 0; i < oldSize; ++i) {
		old[i] = a[i];
	}

	delete [] a;
	a = new double[newSize];

	for(unsigned i = 0; i < newSize; ++i) {
		if( i < oldSize ) {
			a[i] = old[i];
		} else {
			a[i] = 0;
		}
	}
	delete [] old;
}

// It creates a new array at location array 3 with the values of a2 and a1

void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3) {
	size3 = size1 + size2;

	delete [] a3;

	a3 = new double[size3];

	for( unsigned i = 0; i < size1; i++ ) {
		a3[i] = a1[i];
	}

	for( unsigned i = size1; i < size3; i++ ) {
		a3[i] = a2[i - size1];
	}

}
