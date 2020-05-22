/* MatrixTester.h declares test-methods for class Matrix.
 // * Student:  Anna Park(akp5), Einstein Essibu(se27)
// * Date: 03 Mar, 2020
// * Begun by: Joel C. Adams, for CS 112 at Calvin University.
// */

#ifndef MATRIXTESTER_H_
#define MATRIXTESTER_H_

#include "Matrix.h"

class MatrixTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testExplicitConstructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testSubscripts();
	void testReadSubscript(const Matrix& mat);
	void testTranspose();
	void testAddition();
	void testSubtraction();
	void testMultiply();
	void testReadFromStream();
	void testReadFromFile();
	void testWriteToStream();
	void testWriteToFile();
};

#endif /*MATRIXTESTER_H_*/
