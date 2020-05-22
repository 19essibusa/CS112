/* SongTester.h declares a test-class for class Song.
    * Student Name: Einstein Essibu
    * Date: 02/17/2020
    * Begun by: Joel Adams, for CS 112 at Calvin University.
    */
#ifndef SONGTESTER_H_
#define SONGTESTER_H_
#include "Song.h"

class SongTester {
public:
	void runTests();
	void testConstructors();
	void testReadFrom();
	void testOperator();
};

#endif /*SONGTESTER_H_*/
