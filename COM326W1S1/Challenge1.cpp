/*
* FizzBuzz.cpp
*
* Version information
* Author: Ciaran Mcstravick
* Date:
* Description: Solution to week 1 FizzBuzz challenge
*
* Copyright notice
*/

#include <iostream>

using namespace std;

int main() {
	int user_input{};
	
	cout << "Please enter a number greater than one: ";
	cin >> user_input;

	for (int i = 1; i < user_input+1; ++i) {
		if ((i % 3 == 0) && (i % 5 == 0)) {
			cout << "FizzBuzz";
		}
		else if (i % 3 == 0) {
			cout << "Fizz";
		}
		else if (i % 5 == 0) {
			cout << "Buzz";
		}
		else {
			cout << i;
		}
		cout << "\n";
	}

	return 0;
}
