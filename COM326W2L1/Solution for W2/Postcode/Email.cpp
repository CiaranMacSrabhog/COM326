/*
* Email.cpp
*
* Version information
* Author: Ciaran Mcstravick
* Date: 
* Description: Solution to the check for valid emails challenge
* Copyright notice
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;
	
string email{};

//Forward declaration of function
bool IsEmailValid(string email);

//Primitive coding to check emails - You can see how complicated it is to do it without regEx
bool CheckEmailManual(string email);
bool CheckCharacters(string str, int order);

int main() {

	string email;
	bool valid{ 0 };
	do {
		cout << "Please enter an email address: ";
		cin >> email;
		
		if (IsEmailValid(email)) {
			cout << "Thank you" << endl;
			valid = true;
		} 
		
		// Primitive calls
		/*
		if (CheckEmailManual(email)) {
			cout << "Thank you" << endl;
			valid = true;
		}
		*/
	} while (valid != true);
	
	return 0;	
}

bool IsEmailValid(string email) {
	
	//Define a regular expression for the email address
	const std::regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// try to match the string against the regular expression
	return std::regex_match(email, pattern);
}

/* Primitive version of checking for an email.
   Observe the number of lines needed to perform the regex test 
   This is a good reason to LEARN regex properly
   */

bool CheckEmailManual(string email) {
	//Primitive implementation of regex for email
	//Seperate the string at "@"
	size_t found = email.find("@");
	if ( found != string::npos) {
			string substrFirst = email.substr(0, found);
			string substrSecond = email.substr(found + 1, string::npos);
			if (CheckCharacters(substrFirst, 1) != false && CheckCharacters(substrSecond, 2) != false) {
				return true;
			}
			else {
				return false;
			}
	}
	else {
		return false;
	}
}

bool CheckCharacters(string str, int order) {
	bool valid = true;
	int counterDot = 0; //Check multiple occurances for *
	int counterUdr = 0; //Check multiple occurances for _
	if (order == 1) {
		// Check for only characters that you allowed before "@"
		// This should be A-Z, a-z, ".", and "_" (symbols can only occurs once)
		for (int i = 0; i < str.length(); i++) {
			int charpost = int(str.at(i));
			
			if (counterDot > 1 || counterUdr > 1) {
				return false;
			}
			else if (charpost >= 48 && charpost <= 57) {
				valid = true; //valid number
			}
			else if (charpost >= 65 && charpost <= 90) {
				valid = true; //valid capitals
			}
			else if (charpost >= 97 && charpost <= 122) {
				valid = true; //valid small latters
			}
			else if (charpost == 46) {
				counterDot++; //check no of symbols
			}
			else if (charpost == 95) {
				counterUdr++; //check no of symbols
			}
			else {
				return false; // all invalids
			}
		}
	}
	else if (order == 2) {
		for (int i = 0; i < str.length(); i++) {
			int charpost = int(str.at(i));

			if (charpost >= 48 && charpost <= 57) {
				valid = true; //valid number
			}
			else if (charpost >= 65 && charpost <= 90) {
				valid = true; //valid capitals
			}
			else if (charpost >= 97 && charpost <= 122) {
				valid = true; //valid small latters
			}
			else if (charpost == 46) {
				counterDot++; //check no of symbols
			}
			else if (charpost == 95) {
				valid = true; //check no of symbols
			}
			else {
				return false; // all invalids
			}
		}
		if (counterDot < 1) {
			return false;
		}
	}

	// Cleanup for misc. symbols and dot.com entries
	if (str.find("..") != string::npos) {
		return false;
	}

	if (str.rfind(".") == str.length() - 1) {
		return false;
	}

	return valid;
}
