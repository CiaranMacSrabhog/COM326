/*
* Main.cpp
*
* Version information
* Author: Ciaran Mcstravick
* Date:
* Description: Solution to week 1 Collatz challenge
*
* Copyright notice
*/

#include <iostream>

using namespace std;

int steps{ -1 };

/*Function prototype - The function is below the main so the compiler won't know what the function is unless
* you declare it in advance. There isn't a function body however
* see: http://www.learncpp.com/cpp-tutorial/17-forward-declarations/ */
int CalculateCollatz(int n);

int main() {
			
	int userNumber{ 0 };

	cout << "Please enter a natural number to begin: ";

	cin >> userNumber;

	CalculateCollatz(userNumber);

	cout << endl;

	cout << "steps = " << steps << endl;
	return 0;
}


int CalculateCollatz(int n) {
	++steps;
	cout << " " << n;
	if (n == 1) {
		return 1;
	}
	else if (n % 2 == 0) {
		return CalculateCollatz(n / 2);
	}
	else {
		return CalculateCollatz(3 * n + 1);
	}
	return n;
}

