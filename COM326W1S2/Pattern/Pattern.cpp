/*
* Pattern.cpp
*
* Version information
* Author: Ciaran Mcstravick
* Date:25/09/2017
* Description: Solution to week 1 Pattern challenge
*
* Copyright notice
*/

#include <iostream>
using namespace std;

// 16 print a Diamond pattern
int main(int argc, char* argv[]) {
	int size = 9;

	for (int i = 1; i < size; i += 2) {
		for (int k = size; k >= i; k -= 2) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 1; i <= size; i += 2) {
		for (int k = 1; k <= i; k += 2) {
			cout << " ";
		}
		for (int j = size; j >= i; j--) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}

