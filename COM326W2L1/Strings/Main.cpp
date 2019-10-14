/*
* Main.cpp
*
* Version information
* Author: Ciaran Mcstravick
* Date: 
* Description: Solution to the string comparision challenge
* Copyright notice
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void ToLowerCase(char& c);
std::string str_tolower(std::string s);
void toLower(basic_string<char>& s);

int main() {

	string s1, s2, answer;

	cout << " Please enter a string: \t";
	getline(cin, s1);

	cout << " Please enter another string: \t";
	getline(cin, s2);
	
	// A number of alternatives to convert string to any 1 case:
	//transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	//transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

	//std::for_each(s1.begin(), s1.end(), ToLowerCase);
	//std::for_each(s2.begin(), s2.end(), ToLowerCase);

	//s1 = str_tolower(s1);
	//s2 = str_tolower(s2);

	toLower(s1);
	toLower(s2);

	if (s1 == s2) {
		cout << "\n This pleases Chuck Norris!" << endl;
	}
	else {
		cout << "\n I pity the fool" << endl;
	}

	//Check to see if 
	if (s1.find("holiday") != std::string::npos || s1.find("belize") != std::string::npos || 
		s2.find("holiday") != std::string::npos || s2.find("belize") != std::string::npos){
		cout << "\n Are you a secret agent?" << endl;
		getline(cin, answer);
		
		//Using string.find()
		if (answer.find("yes") != std::string::npos) {
			cout << "BANG!" << endl;
		}

		//Use a primitive assignment and string convert
		//toLower(answer);
		//if (answer == "yes")
		//	cout << "BANG! \n";
	}
	return 0;
}

//Different function to convert strings into lowercase
void ToLowerCase(char& c) {
	c = std::tolower(static_cast<unsigned char>(c));
}

std::string str_tolower(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { 
		return std::tolower(c); 
		} 
	);
	return s;
}

void toLower(basic_string<char>& s) {
	for (basic_string<char>::iterator p = s.begin();
		p != s.end(); ++p) {
		*p = tolower(*p);
	}
}
