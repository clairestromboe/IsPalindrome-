//============================================================================
// Name        : ispalindrome.cpp
// Author      : Claire Stromboe
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "functions.h"
#include <string.h>
#include <cctype>

using namespace std;


int main(int argc, char* argv[]) {

	bool isPal = false;
	bool stringExist = false;
	bool flagExist = false;
	int i;

	//invalid input check:
	for (i = 1; i <= argc - 1; ++i){ // checks for a string input
			if (isalnum(toupper(argv[i][0])) > 0){
				stringExist = true;
			}
	}


	if (stringExist == false) { //runs for invalid inputs
		printUsageInfo(argv[0]);
	}


	for(i = 1; i <= argc - 1; ++i){
		if('-' == (argv[i][0])){
			flagExist = true;
		}
	}


	if (flagExist == true){
		int flagLength;
		int j;
		bool cSense = false;
		bool sIgnored = true;

		for (i = 1; i <= argc - 1; ++i){
			if (argv[i][0] == '-'){
				flagLength = strlen(argv[i]);
				for (j = 1; j < flagLength; ++j){
					if (argv[i][j] == 'c' || argv[i][j] == 'C'){
						cSense = true;
					}
					else if (argv[i][j] == 's' || argv[i][j] == 'S'){
						sIgnored = false;
					}
					else{
						printUsageInfo(argv[0]);
					}
				}
			}
		}

		for (i = 1; i <= argc - 1; ++i){
			if (argv[i][0] != '-'){
				cout << "\"" << argv[i] << "\"";
				isPal = isPalindrome(argv[i], cSense, sIgnored);

				if (isPal == true){
					cout << " is a palindrome." << endl;
				}
				else{
					cout << " is not a palindrome." << endl;
				}
			}
		}
	}



	if (flagExist == false){ //in case of no flags
		for (i = 1; i <= argc - 1; ++i){ // checks for a string input
			if (isalpha(toupper(argv[i][0])) > 0){
				cout << "\"" << argv[i] << "\"";
				isPal = isPalindrome(argv[i], false, true);
			}
			if (isPal == true){
				cout << " is a palindrome." << endl;
			}
			else{
				cout << " is not a palindrome." << endl;
			}
		}
	}

}
