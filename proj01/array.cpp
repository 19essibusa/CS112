/* array.cpp defines "C style" array operations
 * Name: Anna Park(akp25), Einstein Essibu(se27)
 * Date: 18 Feb, 2020
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "array.h"

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

			cout << total/size << '\t';
		}
	return 0;
}
