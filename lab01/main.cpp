/* main.cpp tests the classes in our project.
 * Student Name: Einstein Essibu
 * Date: 02/11/20
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "SongTester.h"
#include "PlayListTester.h"
#include "Application.h"

int main()
{
	SongTester sTester;
	sTester.runTests();
	PlayListTester plTester;
	plTester.runTests();
	Application Customer;
	Customer.RunApp();
}
