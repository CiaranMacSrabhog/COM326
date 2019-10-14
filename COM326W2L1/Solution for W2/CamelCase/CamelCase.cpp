/*
* CamelCase.cpp
*
* Version information
* Author: Ciaran Mcstravick
* Date: 
* Description: Solution to the CamelCase challenge
* Copyright notice
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int CheckUpperChar(char c); //A primitive function to check for upper char

int main() {
	string s{};
	int numWords{ 1 };
	
	cout << "Enter a CamelCase word here \n";
	cin >> s;

	//Iterate through the string and count uppercase characters
	for (int i = 0; i <= s.length(); i++) {
		if (::isupper(s[i])) {
			numWords++;
		}
	}

	/*
	//Using the primitive version of the function
	for (int j = 0; j < s.length(); j++) {
		if (CheckUpperChar(s.at(j)) == 1) {
			numWords++;
		}
	}
	*/
	cout << "The number of words is: " << numWords << endl;

	return 0;
}

/*This is a primitive to uppercase letter check custom function - you DO NOT need to code this anymore because 
  in C++, you can use the isupper built in function. This is an example to show that you can code anything with
  ONLY the basic c++ command
*/
int CheckUpperChar(char c) {
	for (int i = 0; i < 27; i++) {
		if (c == char('A' + i))
			return 1;
	}	
}
