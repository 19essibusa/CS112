///*
// * PalindromeTester.cpp
// *
// *  Created on: Apr 20,2020
// *      Author: Einstein Essibu
// */
//


#include "PalindromeTester.h"
#include <cassert>


void PalindromeTester::runTests() {
	cout << "Testing class PalindromeDetector..." << endl;
	testIsPalindrome();
	testPalindromeDetector();
	cout << "All tests passed!\n" << endl;
}

void PalindromeTester::testIsPalindrome() {


	cout << "- testing isPalindrome" << flush;
	PalindromeChecker pc("In.txt", "Out.txt");
	assert(!pc.isPalindrome(""));
	cout << " 0 " << flush;
	string palindrome1 = "civic";
	assert(pc.isPalindrome(palindrome1));
	cout << " 1 " << flush;
	string palindrome2 = "ci vic";
	assert( pc.isPalindrome(palindrome2) );
	cout << " 2 " << flush;
	string palindrome3 = "Ci Vic";
	assert(pc.isPalindrome (palindrome3));
	cout << " 3 " << flush;
	string palindrome4 = "C@$!^&i**v*ic@$";
	assert( pc.isPalindrome(palindrome4) );
	cout << " 4 " << flush;
	string palindrome5 = "Hi Einstein";
	assert( !pc.isPalindrome(palindrome5) );
	cout << " 5 " << flush;
	cout << "Passed!" << endl;
}

void PalindromeTester::testPalindromeDetector() {
	cout << "- testing palindromeDetector" << flush;
	PalindromeChecker p("InwardFile.txt", "OutwardFile.txt");
		ifstream fin("InwardFile.txt");
		ifstream fout("OutwardFile.txt");
		string tempStrIn, tempStrOut;

		while (fin) {
			getline(fin, tempStrIn);
			getline(fout, tempStrOut);
			if (p.isPalindrome(tempStrIn)) {
				assert( tempStrOut == tempStrIn + " ***" );
			} else if (!p.isPalindrome(tempStrIn)) {
				assert( tempStrOut == tempStrIn + "" );
			} else {
				assert( false );
			}
		}

		fin.close();
		fout.close();
		cout << " Passed!" << endl;
	}
