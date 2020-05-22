/*
 * Application.h
 *
 *  Created on: Mar 9, 2020
 *      Author: se27
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "Matrix.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Application {
public:
	void runApp();
	void printMatrix(const Matrix& matrix) const;

private:
	string MatrixFile;
	Matrix Matrix1;
	unsigned myRows;
	unsigned myColumns;
};

#endif /* APPLICATION_H_ */
