
#include <iostream>
#include "functions.h"
#include <string.h>
#include <cctype>
#include <cstring>
using namespace std;


	void makelower(char* &userStr){

		int i = 0;

		while (userStr[i] != '\0') {
			userStr[i] = tolower(userStr[i]);
			i = i + 1;
		}

	}


	void removePunctuation(char* &userStr, bool spacesC){

		int i;
		int count = 0;

		//remove punctuation
		for (int i = 0; userStr[i]; i++){
				if (isalnum(toupper(userStr[i])) > 0 || isspace(userStr[i]) > 0){
					userStr[count++] = userStr[i];
				}
		}
		userStr[count] = '\0';

		count = 0;
		// remove spaces
		if (spacesC == false){
			for (i = 0; userStr[i]; ++i){
				if (isspace(userStr[i]) == false){
					userStr[count++] = userStr[i];
				}
			}
			userStr[count] = '\0';
		}
	}



	bool isPalindromeR(char* userStr){
		//case sensitive, spaces considered (on its own)

		int i;
		int j = strlen(userStr) - 1;
		bool isPal = true;

		for (i = 0; i < strlen(userStr); ++i){
			if (userStr[i] != userStr[j]) {
				isPal = false;
			}
			j = j - 1;
		}

		return isPal;
	}



	bool isPalindrome(char* userStr, bool caseS, bool spacesI){

		bool isPal;

		if (spacesI == false){
			removePunctuation(userStr, true);
		}
		else{
			removePunctuation(userStr, false);
		}


		if (caseS == false){
			makelower(userStr);
			isPal = isPalindromeR(userStr);
		}
		else{
			isPal = isPalindromeR(userStr);
		}

		return isPal;
	}


	void printUsageInfo(char programName[]) {

		cout << "Usage: " << programName << " [-c] [-s] <term> ..." << endl;
		cout << "  -c: turn on case sensitivity" << endl;
		cout << "  -s: turn off ignoring spaces" << endl;

		exit(1); // exits from program
	}





