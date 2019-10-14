/* 
* MarsExploration.cpp
*
* Version information
* Author: Ciaran Mcstravick
* Date: 29/09/2019
* Description: Solution to the Mars Exploration problem
* Copyright notice
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string ConvertUpper(string msg);
int CheckCharacter(char c, int i); 

int main()
{
	string sosMsg, sosUpper;

	// Run the constraints so that message is between 1-99
	do {
		cout << "Please enter your message here: ";
		cin >> sosMsg;
	} while (sosMsg.length() < 1 && sosMsg.length() > 99);
	
	sosUpper = ConvertUpper(sosMsg);
	
	// Create substring of 3 given the sentence
	string substrMsg; // string placeholder for substring
	int index = 0; // counter for subscript
	int errCtr = 0; // counter for error character

	for (int i = 0; i < sosMsg.length(); i+=3) {
		if ((__int64)index + 3 <= sosMsg.length()) {
			substrMsg = sosUpper.substr(i, (__int64)index + 3);

			// Do direct checking here - we know that the index is 3
			errCtr += CheckCharacter(substrMsg.at(0), 83); 
			errCtr += CheckCharacter(substrMsg.at(1), 79);
			errCtr += CheckCharacter(substrMsg.at(2), 83);
		}
	}

	cout << "No of character altered: " << errCtr << endl;
}

string ConvertUpper(string msg) {
	// convert string to upper case
	std::for_each(msg.begin(), msg.end(), [](char& c) {
		c = ::toupper(c);
		}); 
	return msg;
}

int CheckCharacter(char c, int i) {
	if (int(c) == i) {
		return 0;
	}
	else {
		return 1;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
